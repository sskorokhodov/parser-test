Parser project
==============

Introduction
------------

The project is elaboration of test that I wrote to get a new job.
It parse simple tree data structure format file, build tree data structure and writes structure info into new file.

Now it used to learn and try new C++11 features, doxygen comments and boost or google (I didn't decide yet) unit-test library.

Overview
--------

Hear should be functionality description.

### Principles

A link to [plans](#plans_anchor).

### Libraries

1. some multiparagraphs list item

    a new line

2. single paragraph list item

#### Parser

> some quoutes...
>
> and some more...
>
>> and some nested
>
> and some closing

#### Nodes

	void someCode()
	{
		// do something
	}


Examples
--------

Hear should be simple usage examples.

C++ 11 features used in project
-------------------------------

- `override` keyword
- explicit default methods deleting with `delete` keyword
- explicit `default` methods keyword
- uniform initialization syntax with braces
- `noexcept` specification
- "move" constructor initialized with rvalue reference
- `auto` keyword type inference
- class inheritence preventing with `final` keyword
- `std::shared_ptr`
- range-based for-loop
- strongly typed enumerations
- new string literals (`u8"Some UTF-8 text: العربية, Česky, 日本語"`)
- lambda functions and expressions

<a id="plans_anchor"></a>Plans
-----

- add ability to get node by its name (std::map? Should it be multimap with
ability to iterate over equally named nodes with "next()"?)
- add Writer to save nodes structure in source format
- doxygen comments
- unit-tests
- CMake build system
- to use more C++ 11 features
- to make as many work as possible at compilation time

* * *

