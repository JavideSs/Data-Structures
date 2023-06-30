# Data Structures
Data structures in C++ from scratch.

It is a project for the [Programming and Data Structure](https://cvnet.cpd.ua.es/Guia-Docente/?wlengua=en&wcodasi=34016&scaca=2020-21) subject at the University of Alicante.

A calendar object [tcalendario](include/tcalendario.h) is used as the item of these data structures:

- Vector : [tvectorcalendario](include/tvectorcalendario.h).
- List : [tlistacalendario](include/tlistacalendario.h).
- Binary Search Tree : [tabbcalendario](include/tabbcalendario.h).
- AVL Tree : [tavlcalendario](include/tavlcalendario.h).

---

## Structure explained

[evalua.sh](evalua.sh) is a script developed for Linux to run tests.

---

## How to use it
Is platform independent.
makefile developed for Linux.

There is an example in [src/main.cpp](src/main.cpp).

```
# Build with make
make    #make clean to remove binaries

# Build without make
g++ -w -O3 -Iinclude lib/* src/main.cpp -o main

# Run main
./main
```

---

Author:  
Javier Mellado Sánchez  
2021