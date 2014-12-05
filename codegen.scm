(use atomic)

(module codegen (gen-program)
(import chicken scheme extras)
(import pat)
(import atomic)

(define (concatenate lists)
  (apply append lists))
(define (concat-map f l)
  (concatenate (map f l)))

(define (gen-exp e)
  (match e
    ;; (`(make-closure ,f ,v) =>
    ;;  `(scm-make-closure ,f ,(map gen-exp v)))
    
    (`(,f . ,args) => `(,f . ,(map gen-exp args)))
    (else
     (cond ((symbol? e) e)
           ((string? e) `(scm-string-to-vector ,e))
           ((number? e) `(make-struct (struct scm) (tag 0) (val.i ,e)))
           (else (error e))))
    ))

(define (iota n) (iota* 0 n))
(define (iota* i n)
  (if (< i n)
      (cons i (iota* (+ 1 i) n))
      '()))

;; if someone allocates a vector and doesn't use it we will die
(define (gen-body body)
  (match body
    (`(direct ,x) =>
     (list x))
    (`(set! ,v (vector . ,elts)) =>
     (let ((elts (map gen-exp elts)))
       (cons `(set! ,v (allocate-vector ,(length elts)))
             (map (lambda (e i)
                    `(scm-vector-insert! ,v ,e ,i))
                  elts
                  (iota (length elts))))))
    (`(set! ,v ,e) => (list `(set! ,v ,(gen-exp e))))
    (`(return ,r) => (list `(return ,r)))
    (`(if ,b (begin . ,t) (begin . ,e)) =>
     (list `(if (scm-extract-truth ,(gen-exp b))
                (begin . ,(concat-map gen-body t))
                (begin . ,(concat-map gen-body t)))))
    (else (list (gen-exp body)))
    ))

(define (gen-definition definition)
  (match definition
    (`(define (,name . ,args) ,declarations . ,body) =>
     (let ((c-args (map (lambda (arg)
                          `((struct scm) ,arg))
                        args)))
       `(define ((struct scm) ,name . ,c-args)
          . ,(append (map (lambda (var)
                            `(declare (struct scm) ,var))
                          declarations)
                     (concat-map gen-body body)))))
    (else (error (list "Invalid exp!" definition)))))

(define (gen-program program)
  (cons
   `(include "runtime.c")
   (map gen-definition program)))

)
