
# Generic MeTTa encoding/decoding.
ADD_LIBRARY(metta-io
	DecodeMeTTa.cc
	EncodeMeTTa.cc
)

# ADD_DEPENDENCIES(metta opencog_atom_types)

TARGET_LINK_LIBRARIES(metta-io
	atomspace
)

INSTALL (TARGETS metta-io EXPORT AtomSpaceTargets
	DESTINATION "lib${LIB_DIR_SUFFIX}/opencog"
)

INSTALL (FILES
	MeTTa.h
	DESTINATION "include/opencog/atoms/metta"
)

# -------------------------------
