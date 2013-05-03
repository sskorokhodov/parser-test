Introduction
------------

The project is elaboration of test that I wrote to get a new job.
It parse simple tree data structure format file, build tree data structure and writes structure info into new file.
Now it used to learn and try new C++11 features, doxygen comments and boost or google (I didn't decide yet) unit-test library.

Overview
--------

Hear should be functionality description.

Examples
--------

Hear should be simple usage examples.

C++ 11 features used in project
-------------------------------

- _override_ keyword
- explicit default methods deleting with _delete_ keyword
- explicit _default_ methods keyword
- uniform initialization syntax with braces
- _noexcept_ specification
- "move" constructor initialized with rvalue reference
- _auto_ keyword type inference
- class inheritence preventing with _final_ keyword
- _std::shared_ptr_
- range-based for-loop
- strongly typed enumerations
- new string literals (u8"")
- lambda functions and expressions

Plans
-----

- add ability to get node by its name (std::map? Should it be multimap with
ability to iterate over equally named nodes with "next()"?)
- add Writer to save nodes structure in source format
- doxygen comments
- unit-tests
- CMake build system
- to use more C++ 11 features
- to make as many work as possible at compilation time
