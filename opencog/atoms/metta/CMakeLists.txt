
# The atom_types.h file is written to the build directory
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_BINARY_DIR})

ADD_LIBRARY (metta-ast SHARED
	MettaAST.cc
)

# The metta.scm opencog-ext-path-metta define is built
# implcitly from this directory name. So we have to have this, here.
ADD_GUILE_EXTENSION(SCM_CONFIG metta-ast "opencog-ext-path-metta")

# Without this, parallel make will race and crap up the generated files.
ADD_DEPENDENCIES(metta-ast metta_atom_types)

TARGET_LINK_LIBRARIES(metta-ast
	metta-types
	metta-io
	atomspace
)

INSTALL (TARGETS metta-ast EXPORT AtomSpaceTargets
	DESTINATION "lib${LIB_DIR_SUFFIX}/opencog"
)

INSTALL (FILES
	MettaAST.h
	DESTINATION "include/opencog/atoms/metta"
)
