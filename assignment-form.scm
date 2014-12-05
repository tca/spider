(use sequence atomic) ;; the program compiles but fails without this

(module assignment-form (assignment-form assignment-form-program)
(import chicken scheme)
(import pat sequence atomic)

(define (assignment-form* t r gen-sym)
  (match t
    (`(begin) => (error "I don't know how to handle empty begin"))
    (`(begin ,x) => (assignment-form* x r gen-sym))
    (`(begin ,x . ,y) => `(join ,(assignment-form* x #f gen-sym)
                                ,(assignment-form* `(begin . ,y) r gen-sym)))
    (`(if ,b ,t ,e) =>
     (let ((b-r (gen-sym "r")))
       `(join ,(assignment-form* b b-r gen-sym)
              (elt (if ,b-r
                       (begin . ,(assignment-form t r gen-sym))
                       (begin . ,(assignment-form e r gen-sym)))))))
    (`(make-closure ,f ,v) =>
     (let ((r2 (gen-sym "r")))
       `(join
         ,(assignment-form* v r2 gen-sym)
         (elt ,(if r
                   `(set! ,r (make-closure ,f ,r2))
                   `(make-closure ,f ,r2))))))
    (`(scm-wrap-fptr ,p) =>
     (if r
         `(elt (set! ,r (scm-wrap-fptr ,p)))
         `(elt (scm-wrap-fptr ,p))))
    (`(invoke-closure ,clo . ,args) => ;; TODO insert asserts
     (let ((results (map (lambda (_) (gen-sym "r")) args)))
       (let ((clo-r (gensym "clor"))
             (clo-fptr (gensym "clo"))
             (clo-env (gensym "env")))
         `(join (join (join (elt (direct (declare (struct scm) ,clo-r)))
                            ,(assignment-form* clo clo-r gen-sym))
                      (cat ,(map (lambda (arg result)
                                   (assignment-form* arg result gen-sym))
                                 args results)))
                (join (join (elt (direct (declare (type scm-fptr) ,clo-fptr)))
                            (elt (direct (declare (struct scm) ,clo-env))))
                      (join (join (elt (direct (set! ,clo-fptr (struct-ref (struct-ref
                                                                            (array-ref (struct->ref (struct-ref (struct-ref ,clo-r val) v) elt) 0)
                                                                            val) f))))
                                  (elt (direct (set! ,clo-env (array-ref (struct->ref (struct-ref (struct-ref ,clo-r val) v) elt) 1)))))
                            (elt ,(if r
                                      `(set! ,r (,clo-fptr ,clo-env . ,results))
                                      `(,clo-fptr . ,results)))))))))
    (`(,f . ,args) =>
     (begin (unless (symbol? f) (error (list "Invalid function call with head" f)))
            (let ((results (map (lambda (_) (gen-sym "r")) args)))
              `(join (cat ,(map (lambda (arg result)
                                  (assignment-form* arg result gen-sym))
                                args results))
                     (elt ,(if r
                               `(set! ,r (,f . ,results))
                               `(,f . ,results)))))))
    (else (if (or (symbol? t) (atomic? t))
              (if r
                  `(elt (set! ,r ,t))
                  `nil)
              (error (list "Not a valid expression" t))))))
(define (assignment-form t r gen-sym)
  (sequence->list (assignment-form* t r gen-sym)))

(define (assignment-form-def d)
  (match d
    (`(define (,name . ,args) ,body) =>
     (let* ((collect '())
            (gensym (lambda (seed)
                      (let ((result (gensym seed)))
                        (set! collect (cons result collect))
                        result))))
       (let ((a-body (let ((r (gensym "r")))
                       (sequence->list
                        `(join ,(assignment-form* body r gensym)
                               (elt (return ,r)))))))
         `(define (,name . ,args)
            ,(reverse collect)
            . ,a-body))))
    (else (error (list "assignment-form: Invalid exp!" d)))))

(define (assignment-form-program p)
  (map assignment-form-def p))

(define tests
  '(1
    2
    3
    (begin 1)
    (begin 1 2 3)
    (f 1)
    (f 1 2 3)
    (f (g 1) (g 2))
    (f (g 1 2) (g 1 2 3))
    (begin (f 1) (f 2) (f 3))
    (f (begin 1 2 3))
    (f (begin 1 2) (begin 2 3))
    (if #t 1 2)
    (if #f 1 2)
    (if (f 1) (f 2) (f 3))
    (f (if (f 1) (f 2) (f 3)))
    (f 1 2 (if (begin (h) (f 1)) (begin (j) (f 2)) (begin (k) (f 3))))
    (begin 1 2 (f 3))
    (begin (f 1) (f 2) 3)
    ))

(define (run-tests)
  (for-each (lambda (test)
              (display test) (newline)
              (display (assignment-form test 'r)) (newline)
              (read))
            tests))

)
