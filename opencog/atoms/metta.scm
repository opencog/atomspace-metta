;
; Opencog MeTTa atom-types module
;
(define-module (opencog metta))

(use-modules (opencog))
(use-modules (opencog metta-config))

; Load the C library that calls the classserver to load the types.
(load-extension
   (string-append opencog-ext-path-metta "libmetta-types")
   "metta_types_init")

(load-from-path "opencog/metta/types/metta_types.scm")
