
MeTTa on the AtomSpace
======================
The MeTTa concept can be implemented on top of the AtomSpace. This repo
contains a proof-of-concept.

### Status

***Version 0.0.1***

A fraction of the MeTTa language can be easily imported as Atomese.
The code here is a proof of concept of this mapping.  At this time,
only the simplest mapping is done: the declaration of functions.

The code "works"; see the
[MeTTa example](./examples/metta-lisp.scm)
for a working demo.

### Architecture
This code makes use of the "Foreign Abstract Syntax Tress"
(`ForeignAST`) code in the base AtomSpace. This AST code also supports
a proof-of-concept for DataLog. See
https://github.com/opencog/atomspace/tree/master/opencog/atoms/foreign

### TODO
Implement `match`, `ground`, and multivalued propagation.

* `match` takes some space, a pattern, and a template does two-sided
  matching of the pattern on the space (i.e. unification) and fills
  in the bindings in the template, and returns all results. So, like
  `MeetLink` but it also unifies.  The unifier code in the
  [opencog/unify git repo](https://github.com/opencog/unify)
  can be used for that.

* `ground` takes some Python/C/Rust function and binds it to a symbol
  This is handled in the base AtomSpace, with the `lib:` wrapper.
  It just needs to be exposed here.

* Multivalued propagation means a function can return more than one
  thing, and its arguments can be multi-valued too. It will expand that
  appropriately.  So, for example,
  `(= A x); (= A y); !(P A A)` returns
  `{(P x x), (P x y), (P y x), (P y y)}`
  Cartesian product.


### Prerequisites

To build the MeTTa layer, the packages listed below are required.

###### AtomSpace
* The OpenCog AtomSpace.
* https://github.com/opencog/atomspace
* It uses exactly the same build procedure as this package. Be sure
  to `sudo make install` at the end.


### Building

Be sure to install the pre-requisites first!
Perform the following steps at the shell prompt:
```
    cd to project root dir
    mkdir build
    cd build
    cmake ..
    make -j4
    sudo make install
    make -j4 check
```
Libraries will be built into subdirectories within build, mirroring
the structure of the source directory root.

### Running
See the `examples` subdirectory.
