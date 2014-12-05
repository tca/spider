(module sequence (sequence->dlist sequence->list)
(import chicken scheme)
(import pat)

;; (define (foldr f z l)
;;   (if (null? l)
;;       z
;;       (f (car l) (foldr f z (cdr l)))))
(define (sequence->dlist s rest)
  (match s
    (`nil => rest)
    (`(join ,x ,y) => (sequence->dlist x (sequence->dlist y rest)))
    (`(cat ,seqs) => (foldr sequence->dlist rest seqs))
    (`(elt ,x) => (cons x rest))
    (else (error (list "invalid sequence" s)))))
(define (sequence->list s)
  (sequence->dlist s '()))


)
