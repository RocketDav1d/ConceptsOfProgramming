

# Concepts of Programming

## Functional Programming

---

## Declarative Programming

> programms describe the logic of a computation without control flow

> "Declare what result you want"

* `SQL` - describe which data I want to receive {.fragment}
* `Prolog` - query (infer) logical relations {.fragment}
* makefiles - describe dependencies {.fragment}

--

### Prolog

```
mother(marge, bart).
mother(marge, lisa).

father(homer, bart).
father(homer, lisa).
```

[Example by by Aja Hammerly](https://www.youtube.com/watch?v=3TBq__oKUzk)

--

### SQL

```
SELECT * FROM Data 
    WHERE BirthDate < '2005-03-15' 
    ORDER BY FirstName
```

--

### C#-LINQ

```
var adults = from d in data
                    where d.age > 18
                    orderby d.firstName
                    select new { name = d.fullName };
```

--

### Benefits

* "Self Documenting" {.fragment}
* High signal to noise ratio {.fragment}
* Composable {.fragment}

--

### Drawbacks

* Impedance mismatch - when the model does not exactly match the problem {.fragment}
* Small changes in code can have big effects - and vice versa. {.fragment}
* Difficult to control what happens when. {.fragment}
* Difficult to Debug - state is hidden, difficult to see where things went wrong {.fragment}

---

## Functional Paradigm

* Idempotent code - a functions return value depends only on its arguments {.fragment}
* referential consistency - each expression can be substituted by its value {.fragment}
* Immutable data structures and algorithms - No mutable state  {.fragment}

--

### Benefits

* Easier to reason about {.fragment}
* Easier to test {.fragment}
* Easier to use in async contexts {.fragment}

--

### Drawbacks

* unfamiliar {.fragment}
  * feels backwards - you start with the end state {.fragment}
  * feels like puzzle solving {.fragment}
* mismatch with hardware. hw is imperative and stateful {.fragment}

---

### No State

How do we do anything without changing state?

--

### Rebinding

> Python example

But pure functional languages do not allow rebinding {.fragment}

--

### Subexpressions

```
calc a b c d = r
    where               -- order is not important
    r = x * y
    x = a + b
    y = c + d
```

--

### Spot the state

```
function sum(list) {
    let s = 0
    for(let i = 0; i < 10; ++i) {
        s += list[i]
    }
    return s
}
```

--

###  Recursion

#### Look ma: no state

```
sum () = 0
sum (x:xs) = x + sum(xs)
```

---

## Higher Order functions

* allow to pass functions to functions {.fragment}
* allow to return functions from functions {.fragment}

> Python example {.fragment}

---

## Monads

> The real world is stateful

how do we deal with that in FP?

--

```cpp
auto make_cat_meme(Image img) -> Image {
    return
        add_rainbow(
            shrink( 
                add_sparkly_eyes(
                    add_bowtie(
                        crop_cat(img)
        ))));
}
```

[Example by Sy Brand](https://blog.tartanllama.xyz/optional-expected/)

--

```cpp
auto make_cat_meme(Image img) -> Image {
    return crop_cat(img)
            >>= add_bowtie
            >>= add_sparkly_eyes
            >>= shrink
            >>= add_rainbow;
}

```

---

# Concepts of Programming Mini LISP

## lisCOp

--

## Expression based

```lisp
(+ 4 5) # evaluates to -> 9
```

--

## Predefined functions

+, =, print, list, first, rest, append

```lisp
(+ 1 2) # -> 3
(= 1 1) # -> true
(= 1 2) # -> () which is an empty list and equivalent to false
```

--

```lisp
(print 1) # outputs  1
```

```lisp
(list 1 2 3) # -> (1 2 3)
```

--

```lisp
(first (list 1 2 3)) # -> 1
(rest (list 1 2 3)) # -> (2 3)
(append (list 1 2 3) 4) # -> (1 2 3 4)
```

--

## bind expressions

```lisp
(define a 1)  # a is bound to 1
(define b (+ 3 4)) # b is bound to 7
```

--

## define functions

```lisp
(define twice (lambda (a) (+ a a)))  # twice is a function that calculates a + a
(define sum (lambda (a b) (+ a b))) 
```

--

## Conditionals

```lisp
(define a 5)
(if (= a 7) (twice a) (twice 2)) # evaluates to 4 (twice 2)
(if (= a 5) (twice a) (twice 2)) # evaluates to 10 (twice a)
```

---

## Quick Task

> write a function that returns the number of elements in a list {.fragment}

> write a function that accumulates the sum of all the values in a list {.fragment}

TODO: create syntax cheetsheet
---

# Homework

* Write a mini lisp interpreter

or alternatively

* Write a [Brainf$#k](https://en.wikipedia.org/wiki/Brainfuck) interpeter (easier)

---

Thank You!
