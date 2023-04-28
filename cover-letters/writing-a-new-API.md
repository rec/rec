# How to write a Python open source data processing project

I thought I would try jotting down what I felt best practice was for a
contemporary open source data project is, in no particular order.

## Git

I could write too much, so this is in shorthand.

This is much less material than it appears, aimed at "as little busywork as
possible".

### Commit messages...

...are like in this classic [article](https://cbea.ms/git-commit/) but not
(yet?) going as far as [Conventional
Commits](https://www.conventionalcommits.org/en/v1.0.0/)

Rationale: consistent messages are an easier read, but cruft is cruft.

### Work in forks, `main` is truth

The idea: `<owner>/<repo>/main` or just `main` is the single source of truth,
and is updated frequently. Periodically a release is declared, and is published
(to PyPi or elsewhere).

Everyone works in branches in their own fork
`<worker>/<repo>/<some-cool-branch-name-not-main>` but stays very close to
`main` with frequent small rebases, mostly done without manual intervention.

Rationale: sharing a fork with other developers is like working in the same
directory on the same machine with them.

No merge commits, no automatic squashes, what is reviewed is what you get,
pulled right into `main`.

Rationale: a merge commit has two parents, so your git history is no longer a
tree: `git-rebase`, `git-bisect` and other tools work less well or not at all.

Work happens in disposable short- or medium-term branches on forks, with tiny
rebases if needed to stay as close to head as possible.

Rationale: working close to `main` and frequently pulling small commits reduces
risk and is good for rapid development.

### All commits go through pull requests.

Correctness and coherence is only enforced at a commit level: pull requests with
several unrelated small commits are possible, or one with a single big commit.

All pull requests must receive some sort of review. In very earliest development
that might be as little as a single developer doing a quick once-over of their
own work and pushing it, but soon...

Pull requests should be almost as high priority as emergencies, as they are
blocking.

But coding is fun. Reviewing is less fun. The writer should spend three minutes
to save the reviewer two minutes.

### Is rewriting history on `main` allowed?

For example, can you amend and push to `main` for a spelling mistake in the
commit message?  What about if you think you can just make the commit message a
bit clearer?

I break a little with tradition here by saying "Occasionally".

In a small team doing rapid development, if we are using the above workflow,
then the occasional trivial rewrite of the tip is not even going to be noticed
by the other developers and if we are working fast we should be prepared to make
tiny short-lived mistakes that we can clean up without bothering others.

I would say, "To be avoided without a good reason".  Most of this should be done
on your own fork.

### I have open source tooling for a lot of this

https://github.com/rec/gitz, but you can accomplish all the above easily with
only `git-new`, `git-update`, `git-rebase`, and a one-time setting of each
developer's global git config variables.

## Which version of Python?

Are we writing an entirely stand-alone program? Or will there also be a module
that people can import into their own Python programs? Rather rhetorical q, it
is the second.

This means we need to support a fairly old version of Python.  Some people
support Python 2 still! :-o

But I'm going to propose we write to Python 3.8, because this is a new project.

Rationale:

* 3.7 is end-of-life in eight weeks.
* 3.8 is the recommended version for PyTorch.
* 3.8 introduces a new syntax, `:=` the walrus operator.
* Many useful changes in 3.9-3.11 are just in libraries and can be trivially or
easily backported if we support `:=`.

(The changes we can't use that way are mostly with typing...)

One possibility that worked well in my previous project for me was to develop
using Python 3.11 and test everything with 3.8 before submitting. The reason to
do this was not the marginal ~~10% speedup but the truly excellent error
messages that newer Pythons have, as well as proving that the code works there.

## Python dependency management, packaging and environments

Poetry and pyproject.toml are the only way to go, I believe.
https://python-poetry.org/docs/

If you do that you get PyPi for free, Anaconda if you want it (I know zip about
that whole world) and a lot of other things like version management.

Using some sort of virtual environment should be strongly encouraged.

Poetry gives you one for free but it is important that we should be open to
running in any sort of Python environment, even "the system Python". (If you're
running in a docker, why not install into the system Python?)

I use [direnv](https://direnv.net/), very handy, we should support that too
("supporting" means only "adding two entries to .gitignore" and "not being
deliberately stupid").

## Automatic testing

### `pytest`: very common, works well, what's not to like?

### Coverage

"Very high" but also "very focused". Testing first needs to be an aggressive,
nasty business aimed at teasing out the bugs that are certainly there, and only
later become a genteel maintenance process of continuing to prove correctness.

### The gotcha: "all these databases" and "all these platforms"

Proper testing is going to have to test against all the databases and
non-database formats we support, using different test databases, some
comparatively large, that need to be identical across development machines.

This means that the "setup" and "teardown" phases might take minutes to
complete, which is clearly incompatible with rapid development.

It is easy to cache these databases for the developer, but this prevents a
challenge for continuous integration (a chore rather than a roadblock).

(I have a neat organizational solution I have used to deal with this complexity
this a couple of times before.)

And at some point, there are also multiple platforms - at least BSD/Darwin vs
Linux, but Windows would have to appear on the roadmap. Three platforms times
six databases is not huge, but needs to be managed.

CI will do the heavy lifting there for individual developers so we don't have to
have 18 dockers all running.

## Code correctness tools

###  [`flake8`](https://flake8.pycqa.org/en/latest/)

Yes, with [few](https://github.com/PyCQA/flake8/issues/494) adjustments.

### `flake8` extensions

Maybe, some, if they don't slow us down, no cruft.

###  [`black`](https://pypi.org/project/black/):

The arguments for black, that the code looks uniform, are convincing, but I
find that it produces code that is too compact, particularly when you are
dealing with CLI APIs where even in well-managed code, you often have dozens of
rather complex parameters to a single function.

So still, tentatively yes, with these adjustments:

* canonicalize quotes to `'` to save our pinkies
* allow developer "opt-outs" (you are allowed mark a section as "not black")
* use `flake8` default width

### [`impall`](https://pypi.org/project/impall/)

Yes: tiny install, zero maintenance, occasionally catches things.

## Allowed text file formats (not binary)

We should allow JSON, [JSON Lines](https://jsonlines.org/), TOML and Yaml files.

Rationale:

* JSON is everywhere.
* JSON Lines is near-trival and convenient for record-oriented data in quantity
* TOML is very good for human-edited configs, and Python is moving to this
* Yaml has [numerous
defects](https://tomswirly.medium.com/yaml-is-an-extremely-bad-choice-for-any-configuration-file-because-its-wildly-unpredictable-d37969d20fef)
but is in demand.

We should by default write JSON or JSON Lines for machine readable data, and
TOML for human-readable configs.

### Typing and `mypy`

This is a bucket of worms.

There are three different levels of using Python type annotatons in your code.

1. You can ignore them completely.

2. You can add Python type annotations to some of your code purely as a form of
documentation but not have the annoations checked.

3. Or you can require type checking on your code, and run automatic type
checkers on the code (typically `mypy`), to avoid type errors.

Coming as I do from strongly typed languages, I really expected that I would
prefer the third, complete type checking solution.

Unfortunately, my experience has been that Python type checking has found almost
no errors, and occupies far more time than I expected if you want to do it
without cheating (sprinkling `Any` everywhere).

As an example, someone else had to add the typing code to one of my projects
[here](https://github.com/rec/dtyper/blob/cc57018ba88b198998e07bc9729443bd75a67451/dtyper.py#LL208C1-L222C1).
At the time, I thought understood what `P` and `R` were, but clearly I did not
because I do not understand it now without looking it up (and once I understand
something I do not generally forget it).

But even more unfortunately, I do not believe that in a modern,
production-quality open source system, you can get by without checked type
annotations, because a lot of enterprise-scale companies require them.

So IMHO we'll have to have automatically checked type annotations on everything,
_and_ we can't use the nice shorthand formats of Python 3.10:

    from typing import Optional, Union

    def f() -> Optional[str]:
        ...

    def g() -> Union[int, str]:
        ...

becomes

    def f() -> str | None:
        ...

    def g() -> int | str:
        ...

WHINE!


## Documentation builds

Python has struggled with this for years, unfortunately.

Sphinx is tremendously time-consuming to get right and it's very hard to embed
bits of .rst in your code so they get pulled into documentation without often
breaking your .rst files. I've worked in several projects with this and everyone
tiptoed around the Sphinx build...

.md is better and I do extract documentation and put it into .md files that
build HTML from the API but it's quite a blodge because the API extractor is
monolithic, and I am not happy with the results: https://rec.github.io/tdir/
(it's not the style, it's the poor formatting of the API signatures).

Further research is required.

This might be subcontractable to someone cheaper.

## Licensing

Depends entirely on business strategy

## CLIs and GUIs?

If there are more than one or two services that the API provides, a unified CLI
frontend is a very convenient and scalable way to go.

All the cool kids today use Typer because it allows you to define your CLI using
Python type annotations, and then the very cool kids use my `dtyper` because it
lets you automatically turn that into a `dataclass`.

Creating and maintaining such a CLI is fun and easy, there's no reason not to do
it if we expect to release any scripts at all.

Python GUIs aren't so much fun. For example, it's quite possible to make an
error in your Python and have it cause a segfault with no further information,
I've done this with all the most popular GUIs at some time or another (in one
case, just calling their demo from another directory!)

Different errors happen on different platforms, it's a pain.

Matplotlib is pretty epic and pretty reliable, though I have segfaulted that
too, but making it interactive requires some other system.

I've tried a couple of http GUIs, they seemed promising.  There are also
terminal-level GUIs but you can't do any real data visualization of course, and
that's really oldskool.

Another bucket of worms, which is solvable but should be deferred until
necessary.

## Naming of files, projects, directories, databases, etc.

Overall philosophy: allow people not to specify filenames and
then automatically generate a new name with a timestamp in it.

This means you can run the same thing twice and not overwrite the
previous run.  Yes, it means you need to clean up.

(Test database names also have a timestamp in them. When you change the data in
that database, you instead create a new database with a new timestamp and that
new data, so other developers or the CI know to pick that new data up and dump
the old database.)

A full directory path eventually looks like this:

`<data-root><project-root>/<timestamp>/<resource-dir>/<datafile-name>`

Serialization or data sharing happens at the `<resource-dir>` level, one lower
level than you might expect, but that's really useful during development.

Probably the understandability of the above is a bit poor without concrete
examples and maybe it won't come to that level of detail so feel free to ignore
this part.

## What am I missing?

Thanks for reading!
