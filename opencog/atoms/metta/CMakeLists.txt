
# The atom_types.h file is written to the build directory
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_BINARY_DIR})

ADD_LIBRARY (metta-ast SHARED
	MettaAST.cc
)

# Without this, parallel make will race and crap up the generated files.
ADD_DEPENDENCIES(foreign metta_atom_types)

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
