
# The atom_types.h file is written to the build directory
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_BINARY_DIR})

ADD_LIBRARY (metta
	LispAST.cc
)

# Without this, parallel make will race and crap up the generated files.
# ADD_DEPENDENCIES(foreign opencog_atom_types)

TARGET_LINK_LIBRARIES(metta
	atomspace
)

INSTALL (TARGETS foreign EXPORT AtomSpaceTargets
	DESTINATION "lib${LIB_DIR_SUFFIX}/opencog"
)

INSTALL (FILES
	LispAST.h
	DESTINATION "include/opencog/atoms/metta"
)
