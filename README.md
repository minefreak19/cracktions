# Cracktions

A super simple exploration into computing with fractions in C++.

Not by any means a proper C++ project, I just need the operator overloading.

## Concept
The basic idea is that you replace floating point-arithmetic with a structure representing a fraction:
```c
// NOTE: pseudocode

struct Fraction {
    int numerator;
    int denominator;
};
```

The primary benefit of this is escaping from the imprecise approximations of
[IEEE 754][1] floats, and instead transcending into an abstract land of accurate
mathematics (until, of course, you need a number bigger than 2<sup>64</sup>).

## Build and Run
```sh
$ ./build.sh
$ ./cracktions
```

[1]: https://en.wikipedia.org/wiki/IEEE_754 ("IEEE 754")
