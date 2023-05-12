;
; metta-lisp.scm
;
; Experimental demo of a quasi-MeTTa-compatible Lisp-like language.
;
(use-modules (opencog) (opencog exec))
(use-modules (opencog metta))

; Define a factorial function
(MeTTa "(= (fact $x) (if (< $x 2) 1 (* $x (fact (- $x 1)))))")

; Run it.
(cog-execute! (MeTTa "(fact 5)"))

; Define a simple named numeric value
(MeTTa "(= foo 6)")

; Run it.
(cog-execute! (MeTTa "(fact foo)"))
