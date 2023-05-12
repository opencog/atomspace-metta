
OPENCOG_ADD_ATOM_TYPES(atom_types.script
	atom_types.h
	atom_types.definitions
	atom_types.inheritance
	metta_types.scm
	metta_types.pyx
)
ADD_CUSTOM_TARGET(metta_atom_types DEPENDS atom_types.h)

# The atom_types.h file is written to the build directory
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})

ADD_LIBRARY (metta-types SHARED
	MeTTaTypes
)

# Without this, parallel make will race and crap up the generated files.
ADD_DEPENDENCIES(metta-types metta_atom_types)

TARGET_LINK_LIBRARIES(metta-types
	${ATOMSPACE_LIBRARIES}
)

INSTALL (TARGETS metta-types
	LIBRARY DESTINATION "lib${LIB_DIR_SUFFIX}/opencog"
)

INSTALL (FILES
	${CMAKE_CURRENT_BINARY_DIR}/atom_types.h
	DESTINATION "include/opencog/atoms/metta-types"
)

INSTALL (FILES
	${CMAKE_CURRENT_BINARY_DIR}/metta_types.scm
	DESTINATION "${GUILE_SITE_DIR}/opencog/metta/types"
)
