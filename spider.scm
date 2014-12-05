;; rlwrap csi pat.scm sequence.scm atomic.scm verify.scm assignment-form.scm spider.scm -e '(import spider)' -e '(main)'

;; TODO: renaming builtins
;; TODO: wrapping functions
;; TODO: handling invoke-closure

(module spider (main)
(import chicken scheme)
(use extras)
(use pat verify assignment-form codegen)


(define (main debug)
  (let ((file-name (car (command-line-arguments))))
    (let ((content (read-file file-name)))
      (verify-program content)
      (when debug
        (display ";; input program") (newline)
        (for-each (lambda (definition) (pretty-print definition) (newline))
                  content)
        (newline)
        (newline))


      (let ((af (assignment-form-program content)))
        (when debug
          (display ";; assignment form") (newline)
          (for-each (lambda (definition) (pretty-print definition) (newline))
                    af)
          (newline)
          (newline))
        
        (let ((cf (gen-program af)))
          (display ";; c") (newline)
          (for-each (lambda (definition) (pretty-print definition) (newline))
                    cf))
        ))))

(main #f)

)
