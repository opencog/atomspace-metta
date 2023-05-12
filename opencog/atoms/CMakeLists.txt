
DECLARE_GUILE_CONFIG_TARGET(SCM_CONFIG "opencog metta-config" "METTA_TEST")

ADD_SUBDIRECTORY (metta-types)
ADD_SUBDIRECTORY (metta)

WRITE_GUILE_CONFIG(
	${GUILE_BIN_DIR}/opencog/metta-config.scm
	SCM_CONFIG TRUE
)

WRITE_GUILE_CONFIG(
	${GUILE_BIN_DIR}/opencog/metta-config-installable.scm
	SCM_CONFIG FALSE
)

INSTALL(FILES
	${GUILE_BIN_DIR}/opencog/metta-config-installable.scm
	DESTINATION ${GUILE_SITE_DIR}/opencog
	RENAME metta-config.scm
)

ADD_GUILE_MODULE (FILES
   metta.scm
   MODULE_DESTINATION "${GUILE_SITE_DIR}/opencog/metta"
)
