#include <stdlib.h>

#include <set>

#include "rec/util/unused/RandomSelfInverseFunction.h"

namespace rec {
namespace util {

using ByteVector = vector<uint8>;

static int randomItemIndex(int size) {
    return static_cast<unsigned long>(rand()) % size;
}

template <typename T>
static void swap(T& b1, T& b2) {
    T t = b1; b1 = b2; b2 = t;
}

ByteFunction randomSelfInverseFunction(unsigned seed) {
    srand(seed);

    static const int COUNT = ByteFunction::COUNT;

    ByteFunction func;

    ByteVector bytes(COUNT);
    for (int i = 0; i < COUNT; ++i)
        bytes[i] = i;

    while (int size = bytes.size()) {
        auto x = randomItemIndex(size);
        auto y = randomItemIndex(size);
        auto bx = bytes[x];
        auto by = bytes[y];

        func.function[bx] = by;
        func.function[by] = bx;

        if (x < y)
            swap(x, y);

        swap(bytes[x], bytes[size - 1]);
        if (x == y) {
            bytes.resize(size - 1);
        } else {
            swap(bytes[y], bytes[size - 2]);
            bytes.resize(size - 2);
        }
    }

    return func;
}

}  // namespace rec
}  // namespace util
