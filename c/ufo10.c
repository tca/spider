#include "runtime.c"
struct scm scm_main(struct scm);
struct scm g2499(struct scm, struct scm);

struct scm scm_main(struct scm env2498) {
    struct scm r0;
    struct scm r1;
    struct scm r5;
    struct scm r6;
    struct scm r10;
    struct scm clor2;
    clor2 = scm_wrap_fptr(scm_print);
    struct scm clor7;
    clor7 = scm_wrap_fptr(scm_make_vector);
    r5 = (struct scm){ .tag = 0, .val.i = 5 };
    r10 = allocate_vector(0);
    r6 = make_closure(g2499, r10);
    scm_fptr clo8;
    struct scm env9;
    clo8 = clor7.val.v->elt[0].val.f;
    env9 = clor7.val.v->elt[1];
    r1 = clo8(env9, r5, r6);
    scm_fptr clo3;
    struct scm env4;
    clo3 = clor2.val.v->elt[0].val.f;
    env4 = clor2.val.v->elt[1];
    r0 = clo3(env4, r1);
    return r0;
}

struct scm g2499(struct scm env2498, struct scm i) {
    struct scm r11;
    struct scm r12;
    struct scm r13;
    struct scm clor14;
    clor14 = scm_wrap_fptr(scm_vector_ref);
    r12 = scm_string_to_vector("Hello world");
    r13 = i;
    scm_fptr clo15;
    struct scm env16;
    clo15 = clor14.val.v->elt[0].val.f;
    env16 = clor14.val.v->elt[1];
    r11 = clo15(env16, r12, r13);
    return r11;
}

