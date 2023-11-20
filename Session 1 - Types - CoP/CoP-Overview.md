
# Concepts of Programming

---

## What are (data) types?

> Type is an attribute of data that signifies properties of the data.

There are different aspects of types:

--

### Syntactic

> Types are a syntactic signifier

gives the language a handle to distinguish different data types

--

### Representation

> A type is defined in terms of its physical representation and composition

* `int8` - 8 bits that represent a natural number
* `float32` - 32 bits that represent a real number
* a pair of two (adjacent) `int8`

--

### Value space

> A type is defined in terms of possible values.

* `bool` - a value that can represent the two logical states `true` and `false` {.fragment}
* `int8` - a value that represents integers between `-128` to `127` {.fragment}
* grapheme - a single valid unicode grapheme (e.g. 数, 🖖, ä, 1) {.fragment}
* (product type) `pair<int, int>` {.fragment}
* (sum type) `union { int, float, string, array, object }` {.fragment}

--

### Semantics

> A type is defined in terms of it's meaning.

* `CheckedInputString` - a string which contains Input that was checked 

--

### Behavior

> A type is defined in terms of the operations that can be applied to a variable of that type

* `Number` - can be used in Arithmetic


---

## Dynamic vs static typing

When do we check if a type agrees with the behaviour we want

<div style="font-size: small">Interesting history: <a style="font-size: small" href="https://www.youtube.com/watch?v=Tml94je2edk">Why Static Typing Came Back</a></div>

--

### Dynamic Typing

Example: `Python`

##### Types are checked dynamically (= at runtime)

_specifically when a function is called_

--

#### Benefits:

* Functions are exactly as constrained as the implementation requires{.fragment}
* Easier to write "type neutral" code{.fragment}
* More flexible to change implementation{.fragment}
* Less Architectural planing required{.fragment}

--

#### Drawbacks:

* Misses certain kinds of errors{.fragment}
  * can partially be alleviated by rigorous unit tests{.fragment}
* Change carries more risks{.fragment}

--

### Static Typing

Example: `TypeScript`

##### Types are checked by compiler before the first run

--

#### Benefits:

* Functions document and enforce which data they can deal with{.fragment}
* Code changes are less likely to break (esp. silently){.fragment}

--

#### Drawbacks:

* Requires Code to 'convince' the compiler that types are correct{.fragment}
* Some changes become harder and might make bigger architectural changes necessary{.fragment}

---

## Type Conversions

__Attention:__ looks similar, is something else

--

```python
an_int = 42
a_float = 3.1415

res = an_int + a_float

print("an_int  = {:>8} {}".format(an_int, type(an_int)))
print("a_float = {:>8} {}".format(a_float, type(a_float)))

print("res     = {:>8} {}".format(res, type(res)))
```

--

```txt
an_int  =       42 <class 'int'>
a_float =   3.1415 <class 'float'>
res     =  45.1415 <class 'float'>
```

---

## Structural vs duck-typing vs. Nominal typing

What is the criterium for accepting types

--

### Structural Typing

> An object is considered to be (of) a type if their attributes match

Example: `TypeScript`
* [Type Compatibility](https://www.typescriptlang.org/docs/handbook/type-compatibility.html)
* [5 Minute Tutorial](https://www.typescriptlang.org/docs/handbook/typescript-in-5-minutes.html)

--

### Duck-typing

> A Types is accepted (by a function) if their attributes match the required attributes

Example: `duck-types.py`

--

#### Benefits

* Lower coupling of types{.fragment}
* Easy to use types from different sources{.fragment}

--

#### Drawbacks

* No semantic information{.fragment}
  * false positives{.fragment}

---

### nominal typing

> An object is considered to be (of) a type if it declares that it is.

Example: `nominal_typing.py`
Used in most major languages: Python, Java, C++, C#, Swift, ...

--

#### Benefits

* Types can carry semantics{.fragment}
* More type-safety{.fragment}
  * allows overloading{.fragment}

--

#### Drawbacks

* Reduced flexibility{.fragment}
* Higher coupling{.fragment}

---

# Homework

Submit here: https://app.teachfloor.com/code-berlin-se03/c/7963

Deadline: Sat 16 Sep, late evening

After that: Please review and give feedback to 3 other students submissions 

--

## Inheritance

* Give a short introduction to inheritance (~3min video)
  * You select the language
  * Basic usage example
  * How does it work (e.g. JS prototype inheritance is different from Java)

--

## Dependency Injection

* Write a minimal MVC-"App" 
  * (over-engineered "Hello \<Name\>")
    * Model: stores the name
    * View: Displays/ask for the name
    * Controller: the glue between Model/View
  * Add a configuration object
  * Add a logger object

--

* Set up dependency injection
  * Manually
  * Use a DI-Framework
  * Write a mini DI-Injector

---

# Thank You!
