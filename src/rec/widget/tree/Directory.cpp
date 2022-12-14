#include "rec/widget/tree/Directory.h"

#include "rec/util/thread/CallAsync.h"
#include "rec/util/thread/MakeThread.h"
#include "rec/util/Compare.h"
#include "rec/util/partition/Partition.h"
#include "rec/util/file/Util.h"
#include "rec/util/file/VirtualFile.h"
#include "rec/widget/tree/Shard.h"

using namespace juce;

using namespace rec::thread;

namespace rec {
namespace widget {
namespace tree {

Directory::Directory(const NodeDesc& d, const VirtualFile& vf)
        : Node(d, vf),
            children_(nullptr),
            isOpen_(false),
            childrenRequested_(false),
            childrenStarted_(false) {
}

void Directory::requestChildren() {
    Lock l(processingLock_);
    if (!childrenRequested_) {
        processingChildren_.insert(this);
        childrenRequested_ = true;
    }
}

Node* Directory::createChildFile(const partition::Shard& shard) const {
    if (shard.range_.size() > 1)
        return new Shard(desc(), virtualFile(), shard, children_);

    const File& f = (*children_)[shard.range_.begin_];
    VirtualFile vf(virtualFile_);
    vf.add_path(str(f.getFileName()));
    bool isDir = toRealFile(vf).isDirectory();
    return isDir ? new Directory(desc_, vf) : new Node(desc_, vf);
}

void Directory::computeChildren() {
    if (childrenStarted_)
        return;

    childrenStarted_ = true;

    File f = toRealFile(virtualFile_);
    if (f.isDirectory()) {
        resetChildren();
        file::sortedChildren(f, children_);
        range_.begin_ = 0;
        range_.end_ = children_->size();

        partition();
    }
    setProcessing(false);
}

void Directory::partition() {
    partition::ShardArray shards = partition::partitionList(*children_, range_,
                                                                                                                    minPartition());

    for (int i = 0; i < shards.size(); ++i) {
        std::unique_ptr<Node> node(createChildFile(shards[i]));
        node->addListener(this);
        if (isOpen_)
            node->requestChildren();

        MessageManagerLock lock_;
        addSubItem(node.release(), -1);
    }
}

String Directory::getPrefix(const File& f, int letters) {
    return f.getFileName().substring(0, letters + 1).toUpperCase();
}

void Directory::resetChildren() {
    childrenDeleter_.reset(new FileArray);
    children_ = childrenDeleter_.get();
}

void Directory::itemOpennessChanged(bool isOpen) {
    Lock l(lock_);
    isOpen_ = isOpen;
    if (!isOpen)
        return;

    requestChildren();
    getVisitedFile().create();
    repaintItem();
}

Directory::NodeSet Directory::processingChildren_;
CriticalSection Directory::processingLock_;

bool Directory::computeChildrenInBackground() {
    Thread *t = Thread::getCurrentThread();
    if (t && t->threadShouldExit())
        return false;

    Node* node;
    bool result;
    {
        Lock l(processingLock_);
        NodeSet::const_iterator i = processingChildren_.begin();
        if (i == processingChildren_.end() || (t && t->threadShouldExit()))
            return false;

        node = *i;
        processingChildren_.erase(i);
        result = processingChildren_.empty();
    }
    if (t && t->threadShouldExit())
        return false;
    node->computeChildren();

    return result;
}

}  // namespace tree
}  // namespace widget
}  // namespace rec
