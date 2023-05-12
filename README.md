
MeTTa on the AtomSpace
======================
The MeTTa concept can be implemented on top of the AtomSpace. This repo
contains a proof-of-concept.

***Version 0.0.1***

A fraction of the MeTTa language can be easily imported as Atomese.
The code here is a proof of concept of this mapping.  At this time,
only the simplest mapping is done: the declaration of functions.

The code "works"; see the
[MeTTa example](./examples/metta-lisp.scm)
for a working demo.

Most of the rest of MeTTa can be implemented with the AtomSpace unifier.
See the opencog/unify git repo for that.
