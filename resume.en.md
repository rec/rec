# Tom Ritchford

- http://github.com/rec
- tom.ritchford@gmail.com
- +33 07 56 40 90 29
- Rouen, France

Rapid development of highly reliable, performant, scalable, minimal,
clear and maintainable solutions to difficult problems.

Decades of experience! A plethora of projects taken from conception to completion,
production, packaging and distribution.

Expert in Python and C++, conversant in many others.

Productive but careful LLM wrangler and AI assisted coder.

  * audio and DSP
  * real-time control
  * backend
  * search
  * fintech: option modeling, ledgers, position management
  * big data
  * distributed systems
  * and more

"Everything should be made as simple as possible, but no simpler" -various

## Selected Experience

### <span>Sole Developer, `recs`</span> <span>(April 2026 -- Present)</span>

Several years ago, I started writing `recs`, a highly-reliable, automatic, set-and-forget
audio recording program written in Python, for digital mixers in concert halls, studios,
bars and clubs, and for professional or amateur audio archivists, even just for
capturing old mix tapes.

I've been using it for a couple of years for my own needs but my recent embrace of
LLM-assisted coding has meant an explosion of quality and utility. A public release is
anticipated for September 2026


### <span>Senior Software Engineer, Quansight/OpenTeams</span> <span>(May 2024 -- December 2025)</span>

Quansight and OpenTeams are sister consulting companies in America that only work on
open source software.  I was hired by Quansight for Python and C++ as part of their
long-running contract with Meta to maintain the vital PyTorch project.

I added operator decompositions, type annotations, their first type-checker time unit
tests (that later became a battery of such tests) and a lot of testing, quality and
janitor work: particularly fun a set of CI tasks to improve quality that acted as a
gradual ratchet in one direction, parsing Python files to detect missing documentation
or usage of discouraged types.

OpenTeams decided to raise funds to go public, and I got transferred to them in May
of 2025.  The fundraising did not go well, Meta did not renew some contracts, and this
job ended.


### <span>Lead Programmer, SuperDuperDB</span> <span>(May 2023 -- Sep 2023)</span>

https://github.com/SuperDuperDB/superduperdb

SuperDuperDB was not a database, but a Python system integrating existing databases with
AI tools like vector search and LLMs.

I was tasked with making the working Python codebase "professional" so to be released to
the public as a library, and this I did, by writing many `pytest` tests, adding
practically complete typing enforced with `mypy`, refactoring and renaming and removing
cruft, and of course writing reams of readable class, method and function documentation.

I wrote design documents, really my favorite part: for _structured logging, monitoring,
and journaling_ (a small but very useful API which allowed repeatable computation with
fairly marginal extra effort); and for a _fully typed REST server_ (including a tiny
demo!) with an automatically generated OpenAPI specification.

### <span>CTO, Engora</span> <span>(April 2021 -- Feb 2023)</span>

[Engora](https://search.engora.tech/) was an innovative search engine for mechanical
engineering parts.

The founder created a good demo, and then raised money through crowdfunding. I came in
some months after as CTO: I had my hands in everything, but here are the bits I wrote
all of (Python, PostgreSQL, SqlAlchemy):

* A _parts crawler_ over two dozen disparate sites and a million parts, carefully
rate-limited, harvested directly, then proxied, finally using ScraperAPI's fancy new
asynchronous proxy.

* A PostgreSQL _parts database_ with key information from each parts page: I wrote a
small database quickly, then rewrote it entirely four months later.

* A _data store_ based on S3, using multiple providers, with an incremental offsite
"physical" backup stream; and on top of that, a _data resource management system_, for
convenient replication of projects containing multiple, reproducible resources,
including PostgreSLQ databases, directories and sharded files.

* A neat little proprietary _memory-mapped index_ for direct searching and
retrieval, and [Whoosh](https://whoosh.readthedocs.io/en/latest/) for text
searching.

* A Flask _web server_ (using nginx/gunicorn in production) and a couple of Dockers
  supporting all of these.

* Deployment, configuration files and variables, monitoring variables, logging, user
interaction journaling, and other unsexy but satisfying details.

* Practically complete test coverage of almost everything

* And to run all of those, a tidy [`typer`](https://typer.tiangolo.com/) CLI
named `engora`, with over two dozen commands and subcommands, hundreds of flags
and "practically complete" documentation,  used every day by almost everyone in the
company.

### <span> Senior software engineer at Ripple </span> <span>(2014-2016) </span>

Ripple is a financial technology firm with its own eponymous cryptocurrency. I
worked on their flagship application `rippled`, the complex and complicated
C++17 crypto-ledger that implements their XRP cryptocurrency, on the ledger
code, on deployment, debugging, devops, build and monitoring, mostly in C++ with
some Python.

### <span> CTO, World Wide Woodshed </span> <span>(2009-2014) </span>

I had always wanted to write a complete desktop audio application!

World Wide Woodshed's SlowGold was a leader in music practice software from the
1990s. I bought half the tiny company, and was the sole developer for a
brand-new product in C++, with high-quality audio, subtle and intuitive editing
tools, and little details like three second restart after shutdown.

We had many dedicated customers, but not enough to justify keeping in business,
so we shut down, and [open sourced the software](https://github.com/rec/slow_gold)
in 2016.

### <span> Software engineer, Google </span> <span> (2004-2009) </span>

I joined Google New York when it was a single floor overlooking Times Square, worked on
Google's first question-answering system, then their first Music Search, then its
short-lived Real Estate search, all in C++.

This led me to GoogleBase, a database of tens of billions of items planned for millions
of users. Leading a tiny and changing team, over two years we built a universal
reporting and computation framework in Python that I had proposed and designed: it was
still in common use years later.

As a reward for this slog, I was privileged to work on GWS, the front end program,
written in C++ that generated all Google results pages, for i18n, l10n and translations,
and the GWS live experiment framework.

And I interviewed hundreds of engineers, traveling twice to Korea and once to
Hungary for this.

I used C++, Java and Python, and the usual string of Google technologies.

### <span> Senior software developer, Netomat </span> <span> (2001-2004) </span>

Netomat had an innovative rich media tool to let users and advertisers create
and send Netomat "experiences" – little Java applets (it seemed more reasonable
at the time) minisites with animation, sound and internal navigation - to users
who could edit them within the email itself.

I designed and wrote the animation engine and front-end, most of the animation
types and the manual.

Still one of my favorite "neat hacks" ever, I wrote a tool that converted "experiences"
right into Java bytecode, for a 40-80% savings in download and memory size.

## Skills
- Fully LLM enhanced. Careful and systematic prompter. I reinvest a portion of the time I save into
  careful cleaning, clarification and refactoring of the generated code.
- Architecture and high-level design: clean, simple, practical, scale-appropriate, 12-factor
- Brutal, thorough testing and CI
- Python: Flask/SQLAlchemy/Django/FastAPI/Pydantic, numpy, Cython, real-time, packaging,
  typing!, and more...
- C/C++: modern C++11-23, STL/template programming, Boost, concurrency, DSP, Juce, real-time
- Considerable Javascript, strong Linux,  Bash scripting
- Real-time systems: digital audio and DSP, lighting control systems, MIDI
- Data analysis and retrieval: clustering, search and indexing, data pipelines, S3, MapReduce, log analysis
- PostgreSQL database design, use and some admin
- Strong Git (I wrote this: https://github.com/rec/gitz)
- Globalization: Internationalization, localization, translation, Unicode and encodings
- Performance optimization
- Fintech: ledger systems, option models
- Tool building: see my tools dashboard at https://github.com/rec
- .en:N .fr:C1 .nl:B2 .de:B1 .id:A2 .es:A2

## Education
I have a B.Sc. with First Class Honours in Mathematics from Carleton University, Canada.
