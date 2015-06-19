Parser project
==============

Introduction
------------

The project is elaboration of test that I wrote to get a new job.
It parses simple tree data structure and produces a new file with description of the structure.

C++ 11 features used in project
-------------------------------

- range-based for-loop
- lambda functions and expressions
- "move" constructor initialized with rvalue reference
- new string literals (`u8"Some UTF-8 text: العربية, Česky, 日本語"`)
- strongly typed enumerations
- explicit default methods deleting with `delete` keyword
- explicit `default` methods keyword
- `override` keyword
- class inheritance preventing with `final` keyword
- uniform initialisation syntax with braces
- `noexcept` specification
- `auto` keyword type inference
- `std::shared_ptr`

Plans
-----

- doxygen comments
- unit-tests
- CMake build system
- add ability to get node by its name (std::map? Should it be multimap with
ability to iterate over equally named nodes with "next()"?)
- add Writer to save nodes structure in source format
- to use more C++ 11 features

### ToDo (just couldn't find better place for it)

- add hyper/entity links to doxygen comments


[GoogleTest]: https://code.google.com/p/googletest/ "Google C++ testing framework project home page"
[BoostTest]: http://www.boost.org/doc/libs/1_35_0/libs/test/doc/index.html "Boost Test Library introduction page"