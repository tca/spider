#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "scm_fptr.h"
void scm_memory_trace();
void scm_free(int, void*);
void* scm_malloc(int);
struct scm allocate_vector(int);
void scm_vector_insert_bang(struct scm, struct scm, int);
struct scm make_closure(scm_fptr, struct scm);
struct scm scm_wrap_fptr(scm_fptr);
struct scm scm_print(struct scm, struct scm);
int scm_extract_truth(struct scm);
struct scm scm_vector_ref(struct scm, struct scm);
struct scm scm_vector_length(struct scm);
struct scm scm_make_vector(struct scm, struct scm);
struct scm scm_string_to_vector(char*);
struct scm scm_plus(struct scm, struct scm);
struct scm scm_minus(struct scm, struct scm);
struct scm scm_multiply(struct scm, struct scm);
struct scm scm_divide(struct scm, struct scm);
struct scm scm_eq(struct scm, struct scm);
struct scm scm_gt(struct scm, struct scm);
struct scm scm_lt(struct scm, struct scm);
struct scm scm_gteq(struct scm, struct scm);
struct scm scm_lteq(struct scm, struct scm);
void main();

struct scm_vector {
    int len;
    int ref;
    struct scm* elt;
};
union scm_value {
    int i;
    scm_fptr f;
    struct scm_vector* v;
};
struct scm {
    int tag;
    union scm_value val;
};
void scm_memory_trace() {
    fprintf(stderr, "%d %d\n", scm_time, scm_memory_used);
    return;
}

void scm_free(int size, void* p) {
    scm_time = (scm_time + 1);
    scm_memory_used = (scm_memory_used - size);
    scm_memory_trace();
}

void* scm_malloc(int size) {
    scm_time = (scm_time + 1);
    scm_memory_used = (scm_memory_used + size);
    scm_memory_trace();
    return malloc(size);
}

struct scm allocate_vector(int len) {
    struct scm_vector* v;
    v = scm_malloc(sizeof(struct scm_vector));
    v->len = len;
    v->ref = 1;
    v->elt = scm_malloc((sizeof(struct scm) * len));
    return (struct scm){ .tag = 2, .val.v = v };
}

void scm_vector_insert_bang(struct scm vec, struct scm elt, int idx) {
    assert((vec.tag == 2));
    vec.val.v->elt[idx] = elt;
}

struct scm make_closure(scm_fptr p, struct scm c) {
    struct scm clo;
    clo = allocate_vector(2);
    clo.val.v->elt[0] = (struct scm){ .tag = 1, .val.f = p };
    clo.val.v->elt[1] = c;
    clo.tag = 3;
    return clo;
}

struct scm scm_wrap_fptr(scm_fptr f) {
    return make_closure(f, (struct scm){ .tag = 3 });
}

struct scm scm_print(struct scm env, struct scm a) {
    int i;
    struct scm* elt;
    if ((a.tag == 0)) {
        printf("%d\n", a.val.i);
    } else {
        if (((a.tag == 2) || (a.tag == 3))) {
            elt = a.val.v->elt;
            i = 0;
            while ((i < a.val.v->len)) {
                if ((elt[i].tag == 0)) {
                    putchar(elt[i].val.i);
                } else {
                    putchar('?');
                }
                i = (i + 1);
            }
        } else {
            putchar('?');
        }
    }
}

int scm_extract_truth(struct scm x) {
    return (!((0 == x.tag)) || !((0 == x.val.i)));
}

struct scm scm_vector_ref(struct scm vec, struct scm idx) {
    assert((vec.tag == 2));
    assert((idx.tag == 0));
    struct scm* v;
    int i;
    struct scm ret;
    v = vec.val.v->elt;
    i = idx.val.i;
    assert((i < vec.val.v->len));
    ret = v[i];
    return ret;
}

struct scm scm_vector_length(struct scm vec) {
    assert((vec.tag == 2));
    struct scm* v;
    int i;
    struct scm ret;
    i = vec.val.v->len;
    ret = (struct scm){ .tag = 0, .val.i = i };
    return ret;
}

struct scm scm_make_vector(struct scm len, struct scm gen) {
    assert((len.tag == 0));
    assert((gen.tag == 3));
    struct scm v;
    int j;
    int n;
    scm_fptr fn;
    struct scm* elt;
    fn = gen.val.v->elt[0].val.f;
    n = len.val.i;
    v = allocate_vector(n);
    elt = v.val.v->elt;
    j = 0;
    while ((j < n)) {
        elt[j] = fn(gen, (struct scm){ .tag = 0, .val.i = j });
        j = (j + 1);
    }
    return v;
}

struct scm scm_string_to_vector(char* s) {
    struct scm vec;
    int i;
    int l;
    i = 0;
    l = strlen(s);
    vec = allocate_vector(l);
    while ((i < l)) {
        vec.val.v->elt[i] = (struct scm){ .tag = 0, .val.i = s[i] };
        i = (i + 1);
    }
    return vec;
}

struct scm scm_plus(struct scm a, struct scm b) {
    assert((a.tag == 0));
    assert((b.tag == 0));
    return (struct scm){ .tag = 0, .val.i = (a.val.i + b.val.i) };
}

struct scm scm_minus(struct scm a, struct scm b) {
    assert((a.tag == 0));
    assert((b.tag == 0));
    return (struct scm){ .tag = 0, .val.i = (a.val.i - b.val.i) };
}

struct scm scm_multiply(struct scm a, struct scm b) {
    assert((a.tag == 0));
    assert((b.tag == 0));
    return (struct scm){ .tag = 0, .val.i = (a.val.i * b.val.i) };
}

struct scm scm_divide(struct scm a, struct scm b) {
    assert((a.tag == 0));
    assert((b.tag == 0));
    return (struct scm){ .tag = 0, .val.i = (a.val.i / b.val.i) };
}

struct scm scm_eq(struct scm a, struct scm b) {
    if (((a.tag == 0) && (b.tag == 0))) {
        return (struct scm){ .tag = 0, .val.i = (a.val.i == b.val.i) };
    } else {
        return (struct scm){ .tag = 0, .val.i = 0 };
    }
}

struct scm scm_gt(struct scm a, struct scm b) {
    if (((a.tag == 0) && (b.tag == 0))) {
        return (struct scm){ .tag = 0, .val.i = (a.val.i > b.val.i) };
    } else {
        return (struct scm){ .tag = 0, .val.i = 0 };
    }
}

struct scm scm_lt(struct scm a, struct scm b) {
    if (((a.tag == 0) && (b.tag == 0))) {
        return (struct scm){ .tag = 0, .val.i = (a.val.i < b.val.i) };
    } else {
        return (struct scm){ .tag = 0, .val.i = 0 };
    }
}

struct scm scm_gteq(struct scm a, struct scm b) {
    if (((a.tag == 0) && (b.tag == 0))) {
        return (struct scm){ .tag = 0, .val.i = (a.val.i >= b.val.i) };
    } else {
        return (struct scm){ .tag = 0, .val.i = 0 };
    }
}

struct scm scm_lteq(struct scm a, struct scm b) {
    if (((a.tag == 0) && (b.tag == 0))) {
        return (struct scm){ .tag = 0, .val.i = (a.val.i <= b.val.i) };
    } else {
        return (struct scm){ .tag = 0, .val.i = 0 };
    }
}

void main() {
    scm_main((struct scm){  });
}

