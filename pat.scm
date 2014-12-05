(module pat (match)
(import chicken scheme)

;; <pat> ::= <var>
;;         | `<qpat>   ; (quasiquote <qpat>)
;;         | '<s-exp>  ; (quote <exp>)
;; <qpat> ::= <sym>
;;          | ,<pat>   ; (unquote <qpat>)
;;          | (<qpat> . <qpat>)

(begin-for-syntax


;;;;;;;;;;;;;
;; Some list stuff that we need

(define (concatenate lists)
  (apply append lists))

;; data Rose a = a :- [Rose a]
;; merge = map merge' . groupBy ((==)`on`head) . filter (not . null)
;; merge' strings = head (head strings) :- merge (map tail strings)

(define (sift-by comparator thing things)
  (let loop ((to-process things)
             (yes (list thing))
             (no '()))
    (if (null? to-process)
        (values (reverse yes) (reverse no)) ;; !!!!!!!!!!
        (let ((this (car to-process)))
          (if (comparator thing this)
              (loop (cdr to-process) (cons this yes) no)
              (loop (cdr to-process) yes (cons this no)))))))

(define (group-by comparator things)
  (if (null? things)
      '()
      (let ((x (car things)))
        (call-with-values (lambda () (sift-by comparator x (cdr things)))
          (lambda (ys zs)
            (cons (cons x ys)
                  (group-by comparator zs)))))))

(define (filter pred list)
  (if (null? list)
      '()
      (if (pred (car list))
          (cons (car list) (filter pred (cdr list)))
          (filter pred (cdr list)))))

(define (merge sequences)
  (define comparator (lambda (x y) (equal? (car x) (car y))))
  (define (not-null? n) (not (null? n)))
  (map merge* (group-by comparator (filter not-null? sequences))))

(define (merge* sequences)
  ;; invariant: all sequences have the same car
  (list 'branch
        (caar sequences)
        (merge (map cdr sequences))))


;;;;;;;;;;;;;
;; Compilation from a list of patterns to a tree of instructions

(define (compile-pattern pat)
  (cond ((symbol? pat) (list `(bind ,pat)))
        ((and (list? pat)
              (= 2 (length pat)))
         (case (car pat)
           ((quote) (list `(compare-equal? ',(cadr pat))))
           ((quasiquote) (compile-quasipattern (cadr pat)))))
        (else (error "Invalid pattern"))))

(define (compile-quasipattern qpat)
  (cond ((or (symbol? qpat) (null? qpat)) (list `(compare-equal? ',qpat)))
        ((and (list? qpat)
              (= 2 (length qpat))
              (eq? (car qpat) 'unquote))
         (compile-pattern (cadr qpat)))
        ((pair? qpat) (cons '(decons) (append (compile-quasipattern (car qpat))
                                              (compile-quasipattern (cdr qpat)))))
        (else (error "invalid qpat"))))

(define (compile-patterns patterns bodies)
  ;; patterns must finish with bodies
  ;; and bodies 
  (merge (map append
              (map compile-pattern patterns)
              (map (lambda (body) (list (list 'execute body))) bodies))))

(define match-expander-er
  (lambda (form rename compare?)
    (let ((pats (car (cdr form)))
          (results (cadr (cdr form)))
          (stack (caddr (cdr form)))
          (fail (cadddr (cdr form)))
          (%interpret-pat (rename 'interpret-pat)))
      `(,%interpret-pat ()
                        ,(compile-patterns pats results)
                        ,stack
                        ,fail))))
)

;;;;;;;;;;;;;
;; Interpreting the tree of instructions into scheme code

;; (bind <var>)
;; (compare-equal? <s-exp>)
;; (decons)
;; (execute <body>)

(define-syntax interpret-pat
  (syntax-rules (compare-and-destructure bind)
    ((interpret-pat scope () stack failure)
     failure)
    ((interpret-pat scope ((branch (execute <body>) ()) <alternatives> ...) stack failure)
     (let* scope <body>))
    ((interpret-pat scope ((branch (bind <var>) <then>) <alternatives> ...) stack failure)
     (let ((top (car stack))
           (new-stack (cdr stack)))
       (interpret-pat ((<var> top) . scope) <then> new-stack
                      (interpret-pat scope (<alternatives> ...) stack failure))))
    ((interpret-pat scope ((branch (compare-equal? <s-expr>) <then>) <alternatives> ...) stack failure)
     (let ((top (car stack))
           (new-stack (cdr stack)))
       (if (equal? top <s-expr>)
           (interpret-pat scope <then> new-stack failure)
           (interpret-pat scope (<alternatives> ...) stack failure))))
    ((interpret-pat scope ((branch (decons) <then>) <alternatives> ...) stack failure)
     (let ((top (car stack))
           (new-stack (cdr stack)))
       (if (pair? top)
           (let ((stack (cons (car top) (cons (cdr top) new-stack))))
             (interpret-pat scope <then> stack failure))
           (interpret-pat scope (<alternatives> ...) stack failure))))
    ))

(define-syntax match
  (syntax-rules (=> else)
    ((match t (<pat> => <body>) ... (else <else>))
     (let ((stack (list t)))
       (match-expander (<pat> ...) (<body> ...) stack <else>)))
    ((match t (<pat> => <body>) ...)
     (match t (<pat> => <body>) ...
            (else (error "pattern match fell through"))))))

(define-syntax match-expander
  (er-macro-transformer match-expander-er))


)
