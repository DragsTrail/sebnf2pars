A tool for building STEP Part 21 file parsers. This is potentially useful to a lot of people using STEP,
although it is probably only good for Part 21 files based
on ARM-type EXPRESS schemas and requires some
expertise in writing EBNF files.

From the README:

## OVERVIEW ##

---


This sebnf2pars directory contains a tool for automatically generating
C++ classes and a parser for STEP Part 21 files. The directory also
contains one example of applying the tool.

The tool, named sebnf2pars, reads an annotated EBNF file, expected to
be prepared by the tool user.

The tool writes:
  1. a C++ header file defining classes.
  1. a C++ code file implementing the classes further.
  1. a YACC file defining a parser for STEP Part 21 files.
  1. a Lex file for the lexical scanner needed by the YACC file.

No license is required to use the software. The software is all in standard
C++, so it may be compiled and run on any computer for which a standard C++
compiler is available.


---

**[The complete README](http://code.google.com/p/sebnf2pars/wiki/ReadmeFile)**

**If you have a Windows system you are on your own.**

You may also be interested in the [STEP Class Library](https://github.com/mpictor/StepClassLibrary).