#include "runtime.c"
struct scm scm_main(struct scm);
struct scm g2500(struct scm, struct scm);
struct scm g2499(struct scm, struct scm);

struct scm scm_main(struct scm env2498) {
    struct scm r0;
    struct scm r1;
    struct scm r5;
    struct scm r9;
    struct scm clor2;
    struct scm clor6;
    r9 = allocate_vector(0);
    clor6 = make_closure(g2500, r9);
    r5 = scm_wrap_fptr(scm_print);
    scm_fptr clo7;
    struct scm env8;
    clo7 = clor6.val.v->elt[0].val.f;
    env8 = clor6.val.v->elt[1];
    clor2 = clo7(env8, r5);
    r1 = scm_string_to_vector("a");
    scm_fptr clo3;
    struct scm env4;
    clo3 = clor2.val.v->elt[0].val.f;
    env4 = clor2.val.v->elt[1];
    r0 = clo3(env4, r1);
    return r0;
}

struct scm g2500(struct scm env2498, struct scm x) {
    struct scm r10;
    struct scm r11;
    struct scm r12;
    r12 = x;
    r11 = allocate_vector(1);
    scm_vector_insert_bang(r11, r12, 0);
    r10 = make_closure(g2499, r11);
    return r10;
}

struct scm g2499(struct scm env2498, struct scm y) {
    struct scm r13;
    struct scm r14;
    struct scm r18;
    struct scm r19;
    struct scm clor15;
    r18 = env2498;
    r19 = (struct scm){ .tag = 0, .val.i = 0 };
    clor15 = scm_vector_ref(r18, r19);
    r14 = y;
    scm_fptr clo16;
    struct scm env17;
    clo16 = clor15.val.v->elt[0].val.f;
    env17 = clor15.val.v->elt[1];
    r13 = clo16(env17, r14);
    return r13;
}

