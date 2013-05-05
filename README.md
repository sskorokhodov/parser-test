Parser project
==============

Introduction
------------

The project is elaboration of test that I wrote to get a new job.
It parse simple tree data structure format file, build tree data structure and writes structure info into new file.

Now it used to learn and try new C++11 features, doxygen comments and [boost][BoostTest] or [google][GoogleTest] (I didn't decide yet) unit-test library.

Overview
--------

Hear should be functionality description.

### Principles

Some principles.

### Libraries

1. The code to parse.

    Some additional info.

2. The code to work with nodes tree.

    Some additional info.

3. Other code.

    Some description.

#### Parser

Hear should be parser code description.

#### Nodes

Hear should be nodes code description.

#### Other

Hear should be other code description.

Examples
--------

Hear should be simple usage examples.

	void someCode()
	{
		// do something
	}

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
- class inheritence preventing with `final` keyword
- uniform initialization syntax with braces
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
- to make as many work as possible at compilation time

[GoogleTest]: https://code.google.com/p/googletest/ "Google C++ testing framework project home page"
[BoostTest]: http://www.boost.org/doc/libs/1_35_0/libs/test/doc/index.html "Boost Test Library introduction page"
