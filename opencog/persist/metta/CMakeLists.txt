
# Generic MeTTa encoding/decoding.
ADD_LIBRARY(metta-as
	DecodeMeTTa.cc
	EncodeMeTTa.cc
)

# ADD_DEPENDENCIES(metta opencog_atom_types)

TARGET_LINK_LIBRARIES(metta-as
	atomspace
)

INSTALL (TARGETS metta-as EXPORT AtomSpaceTargets
	DESTINATION "lib${LIB_DIR_SUFFIX}/opencog"
)

INSTALL (FILES
	MeTTa.h
	DESTINATION "include/opencog/atoms/metta"
)

# -------------------------------
