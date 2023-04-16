# Tom Ritchford

- <tom.ritchford@gmail.com>
- +31 64 121 2749
- http://github.com/rec
- Amsterdam, Netherlands

Decades of experience; a plethora of projects taken from conception to
completion and production, in areas including search and backend, big data,
audio and DSP, fintech, distributed systems, real time systems and lighting
control, and more; hundreds of thousands of lines of working, tested production
code in two dozen programming languages; expert in Python and C++.

I specialize in rapid development of highly reliable, performant, scalable,
minimal, clear and maintainable solutions to difficult problems.

"Everything should be made as simple as possible, but no simpler."

## Employment Highlights

### <span>CTO, Engora</span> <span>April 2021 -- Jan 2023</span>

[Engora](https://search.engora.tech/) is an innovative search engine for mechanical
engineering parts.

The founder created a good demo, and then raised money through crowdfunding and
Reddit. I came in some months after that, first as a consultant and then as CTO.

As the only full-time programmer I had my hands in everything, but here are the
bits I wrote all of (Python, PostgreSQL):

* A _parts crawler_ over two dozen disparate websites totalling almost a million
parts, carefully rate-limited, first directly, then proxied, finally using
ScraperAPI's fancy new asynchronous proxy, with a _searchable HTTP cache_ in
PostgreSQL.

* A _data store_ based on S3, replicated over multiple providers and with an
incremental offsite "physical" backup stream; and on top of that, a _data
resource management system_, for convenient replication of resources, and
projects containing multiple, reproducible resources, including databases,
directories and sharded files.

* A neat little proprietary _memory-mapped index_ for direct searching and
retrieval, and [Whoosh](https://whoosh.readthedocs.io/en/latest/) for text
searching.

* A Flask _web server_ (using nginx/gunicorn in production).

* Configuration files and variables, monitoring variables, logging, user
interaction journaling, and other unsexy but satisfying details.

* "Practically complete" test coverage of everything

* And to run all of those, a tidy [`typer`](https://typer.tiangolo.com/) CLI
named `engora`, with over two dozen commands and subcommands, hundreds of flags
and "practically complete" documentation.

### <span>Lead developer on BiblioPixel, Maniacal Labs</span> <span> (2016-2019)

Maniacal Lab's BiblioPixel was a popular lighting control program written in
Python that controlled LEDs in strips, matrices, cubes and other layouts, as
well as other lighting systems such as the Philips Hue and DMX.

I rewrote it from the ground up, with a REST server for pixel and higher-level
control, both code and data plug-ins, animators including video feedback with an
IIR filter, and a new data model using `numpy` arrays, leading to very roughly a
30x speedup with perfect backwards compatibility.

Mostly Python, some Cython and C++. (I'd use
[pybind11](https://pybind11.readthedocs.io/en/stable/) instead of Cython if I
had to do it again.)

### <span>Senior software engineer at Ripple </span> <span>(2014-2016) </span>

Ripple is a financial technology firm with its own eponymous cryptocurrency. I
worked on their flagship application `rippled`, the complex and complicated
C++17 crypto-ledger that implements their XRP cryptocurrency, on the ledger
code, on deployment, debugging, devops, build and monitoring, mostly in C++ with
some Python.

While this was a challenging and educational position, I am not willing to work
in the cryptocurrency field at this time.

### <span>CTO, World Wide Woodshed </span> <span>(2009-2014) </span>

I had always wanted to write a complete desktop audio application!

World Wide Woodshed's SlowGold was a leader in music practice software from the
1990s. I bought half the tiny company, and was the sole developer for a
brand-new product in C++, with high-quality audio, subtle and intuitive editing
tools, and little details like three second restart after shutdown.

### <span>Software engineer, Google </span> <span> (2004-2009) </span>

I joined Google New York when it was a single floor overlooking Times Square,
worked on Goo first question-answering system, the first Music Search, then
its short-lived Real Estate search.

This led me to GoogleBase, a database of tens of billions of items planned for
millions of users. Leading a tiny and changing team, over two years we built a
universal reporting and computation framework I had proposed and designed. It
was still in common use years later.

As a reward for this slog, I was privileged to work on GWS, the front end that
generated all Google results pages, for i18n, l10n and translations, and the GWS
live experiment framework.

And I interviewed hundreds of engineers, traveling twice to Korea and once to
Hungary for this.

I used C++, Java and Python, and the usual string of Google technologies.

### <span> Senior software developer, Netomat </span> <span> (2001-2004) </span>

Netomat had an innovative rich media tool to let users and advertisers create
and send Netomat "experiences" – little Java applet (it seemed more reasonable
at the time) minisites with animation, sound and internal navigation - to users
who could edit them within the email itself.

I designed and wrote the animation engine and front-end, most of the animation
types and the manual.

Still one of my favorite "neat hacks" ever, I wrote a tool that converted
"experiences" (animations) right into Java bytecode, for a 40-80% savings in
download and memory size.

## Skills
- Python: flask/SQLAlchemy/Django, numpy, Cython/C++ APIs, real-time, packaging!
- C/C++ expert: modern C++11-20, STL, DSP, concurrency, Juce, Boost, real-time, digital audio
- Java: distributed systems, automatic bytecode generation, animation
- Architecture and high-level design: clean, simple, practical, scale-appropriate designs
- Data analysis and retrieval: clustering, search and indexing, data pipelines,
  S3, MapReduce, log analysis
- CI; brutal testing
- PostgreSQL database design, use and some admin
- Considerable Javascript, strong Linux, `bash`
- Strong`git` (I wrote this https://github.com/rec/gitz)
- Practical DevOps: sysadmin "classic", deployment/release/integration, monitoring and logging
- Globalization: Internationalization, localization, translation, Unicode and encodings
- Performance optimization
- Fintech: ledger systems, option models
- Real-time systems: digital audio and DSP, lighting control systems, MIDI
- Tool building: see the dashboard at https://github.com/rec

## Education
I have a B.Sc. with First Class Honours in Mathematics from Carleton University, Canada.
