
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

Most of the rest of MeTTa can be implemented with the AtomSpace unifier.
See the opencog/unify git repo for that.

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
