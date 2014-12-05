#include "runtime.c"
struct scm foo(struct scm, struct scm, struct scm);
struct scm bar(struct scm, struct scm);
struct scm baz(struct scm, struct scm);
struct scm scm_main(struct scm);
struct scm g2503(struct scm, struct scm);
struct scm g2502(struct scm, struct scm, struct scm);

struct scm foo(struct scm env2501, struct scm foo2498, struct scm bar2499) {
    struct scm r0;
    struct scm r1;
    struct scm r2;
    struct scm r6;
    struct scm clor3;
    r6 = allocate_vector(0);
    clor3 = make_closure(g2502, r6);
    r1 = foo2498;
    r2 = bar2499;
    scm_fptr clo4;
    struct scm env5;
    clo4 = clor3.val.v->elt[0].val.f;
    env5 = clor3.val.v->elt[1];
    r0 = clo4(env5, r1, r2);
    return r0;
}

struct scm bar(struct scm env2501, struct scm baz2500) {
    struct scm r7;
    r7 = baz2500;
    return r7;
}

struct scm baz(struct scm env2501, struct scm quux) {
    struct scm r8;
    r8 = quux;
    return r8;
}

struct scm scm_main(struct scm env2501) {
    struct scm r9;
    struct scm r10;
    struct scm r11;
    struct scm r15;
    struct scm clor12;
    clor12 = scm_wrap_fptr(foo);
    r15 = allocate_vector(0);
    r10 = make_closure(g2503, r15);
    r11 = scm_wrap_fptr(baz);
    scm_fptr clo13;
    struct scm env14;
    clo13 = clor12.val.v->elt[0].val.f;
    env14 = clor12.val.v->elt[1];
    r9 = clo13(env14, r10, r11);
    return r9;
}

struct scm g2503(struct scm env2501, struct scm x) {
    struct scm r16;
    struct scm r17;
    struct scm clor18;
    clor18 = scm_wrap_fptr(scm_print);
    r17 = scm_string_to_vector("scoping seems to work out!");
    scm_fptr clo19;
    struct scm env20;
    clo19 = clor18.val.v->elt[0].val.f;
    env20 = clor18.val.v->elt[1];
    r16 = clo19(env20, r17);
    return r16;
}

struct scm g2502(struct scm env2501, struct scm foo2498, struct scm bar2499) {
    struct scm r21;
    struct scm r22;
    struct scm r26;
    struct scm clor23;
    clor23 = foo2498;
    struct scm clor27;
    clor27 = bar2499;
    r26 = foo2498;
    scm_fptr clo28;
    struct scm env29;
    clo28 = clor27.val.v->elt[0].val.f;
    env29 = clor27.val.v->elt[1];
    r22 = clo28(env29, r26);
    scm_fptr clo24;
    struct scm env25;
    clo24 = clor23.val.v->elt[0].val.f;
    env25 = clor23.val.v->elt[1];
    r21 = clo24(env25, r22);
    return r21;
}

