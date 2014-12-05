#include "runtime.c"
struct scm cons(struct scm, struct scm, struct scm);
struct scm car(struct scm, struct scm);
struct scm cdr(struct scm, struct scm);
struct scm begin(struct scm, struct scm, struct scm);
struct scm print_each(struct scm, struct scm);
struct scm scm_main(struct scm);
struct scm g2501(struct scm, struct scm, struct scm);
struct scm g2500(struct scm, struct scm, struct scm);
struct scm g2499(struct scm, struct scm);

struct scm cons(struct scm env2498, struct scm x, struct scm y) {
    struct scm r0;
    struct scm r1;
    struct scm r2;
    struct scm r3;
    r2 = y;
    r3 = x;
    r1 = allocate_vector(2);
    scm_vector_insert_bang(r1, r2, 0);
    scm_vector_insert_bang(r1, r3, 1);
    r0 = make_closure(g2499, r1);
    return r0;
}

struct scm car(struct scm env2498, struct scm c) {
    struct scm r4;
    struct scm r5;
    struct scm r9;
    struct scm clor6;
    clor6 = c;
    r9 = allocate_vector(0);
    r5 = make_closure(g2500, r9);
    scm_fptr clo7;
    struct scm env8;
    clo7 = clor6.val.v->elt[0].val.f;
    env8 = clor6.val.v->elt[1];
    r4 = clo7(env8, r5);
    return r4;
}

struct scm cdr(struct scm env2498, struct scm c) {
    struct scm r10;
    struct scm r11;
    struct scm r15;
    struct scm clor12;
    clor12 = c;
    r15 = allocate_vector(0);
    r11 = make_closure(g2501, r15);
    scm_fptr clo13;
    struct scm env14;
    clo13 = clor12.val.v->elt[0].val.f;
    env14 = clor12.val.v->elt[1];
    r10 = clo13(env14, r11);
    return r10;
}

struct scm begin(struct scm env2498, struct scm x, struct scm y) {
    struct scm r16;
    r16 = y;
    return r16;
}

struct scm print_each(struct scm env2498, struct scm list) {
    struct scm r17;
    struct scm r18;
    struct scm r19;
    struct scm r20;
    struct scm r24;
    struct scm r28;
    struct scm r32;
    struct scm r36;
    r18 = list;
    if (scm_extract_truth(r18)) {
        struct scm clor21;
        clor21 = scm_wrap_fptr(begin);
        struct scm clor25;
        clor25 = scm_wrap_fptr(scm_print);
        struct scm clor29;
        clor29 = scm_wrap_fptr(car);
        r28 = list;
        scm_fptr clo30;
        struct scm env31;
        clo30 = clor29.val.v->elt[0].val.f;
        env31 = clor29.val.v->elt[1];
        r24 = clo30(env31, r28);
        scm_fptr clo26;
        struct scm env27;
        clo26 = clor25.val.v->elt[0].val.f;
        env27 = clor25.val.v->elt[1];
        r19 = clo26(env27, r24);
        struct scm clor33;
        clor33 = scm_wrap_fptr(print_each);
        struct scm clor37;
        clor37 = scm_wrap_fptr(cdr);
        r36 = list;
        scm_fptr clo38;
        struct scm env39;
        clo38 = clor37.val.v->elt[0].val.f;
        env39 = clor37.val.v->elt[1];
        r32 = clo38(env39, r36);
        scm_fptr clo34;
        struct scm env35;
        clo34 = clor33.val.v->elt[0].val.f;
        env35 = clor33.val.v->elt[1];
        r20 = clo34(env35, r32);
        scm_fptr clo22;
        struct scm env23;
        clo22 = clor21.val.v->elt[0].val.f;
        env23 = clor21.val.v->elt[1];
        r17 = clo22(env23, r19, r20);
    } else {
        struct scm clor21;
        clor21 = scm_wrap_fptr(begin);
        struct scm clor25;
        clor25 = scm_wrap_fptr(scm_print);
        struct scm clor29;
        clor29 = scm_wrap_fptr(car);
        r28 = list;
        scm_fptr clo30;
        struct scm env31;
        clo30 = clor29.val.v->elt[0].val.f;
        env31 = clor29.val.v->elt[1];
        r24 = clo30(env31, r28);
        scm_fptr clo26;
        struct scm env27;
        clo26 = clor25.val.v->elt[0].val.f;
        env27 = clor25.val.v->elt[1];
        r19 = clo26(env27, r24);
        struct scm clor33;
        clor33 = scm_wrap_fptr(print_each);
        struct scm clor37;
        clor37 = scm_wrap_fptr(cdr);
        r36 = list;
        scm_fptr clo38;
        struct scm env39;
        clo38 = clor37.val.v->elt[0].val.f;
        env39 = clor37.val.v->elt[1];
        r32 = clo38(env39, r36);
        scm_fptr clo34;
        struct scm env35;
        clo34 = clor33.val.v->elt[0].val.f;
        env35 = clor33.val.v->elt[1];
        r20 = clo34(env35, r32);
        scm_fptr clo22;
        struct scm env23;
        clo22 = clor21.val.v->elt[0].val.f;
        env23 = clor21.val.v->elt[1];
        r17 = clo22(env23, r19, r20);
    }
    return r17;
}

struct scm scm_main(struct scm env2498) {
    struct scm r40;
    struct scm r41;
    struct scm r45;
    struct scm r46;
    struct scm r50;
    struct scm r51;
    struct scm r55;
    struct scm r56;
    struct scm clor42;
    clor42 = scm_wrap_fptr(print_each);
    struct scm clor47;
    clor47 = scm_wrap_fptr(cons);
    r45 = scm_string_to_vector("Hello");
    struct scm clor52;
    clor52 = scm_wrap_fptr(cons);
    r50 = scm_string_to_vector("World");
    struct scm clor57;
    clor57 = scm_wrap_fptr(cons);
    r55 = scm_string_to_vector("!");
    r56 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo58;
    struct scm env59;
    clo58 = clor57.val.v->elt[0].val.f;
    env59 = clor57.val.v->elt[1];
    r51 = clo58(env59, r55, r56);
    scm_fptr clo53;
    struct scm env54;
    clo53 = clor52.val.v->elt[0].val.f;
    env54 = clor52.val.v->elt[1];
    r46 = clo53(env54, r50, r51);
    scm_fptr clo48;
    struct scm env49;
    clo48 = clor47.val.v->elt[0].val.f;
    env49 = clor47.val.v->elt[1];
    r41 = clo48(env49, r45, r46);
    scm_fptr clo43;
    struct scm env44;
    clo43 = clor42.val.v->elt[0].val.f;
    env44 = clor42.val.v->elt[1];
    r40 = clo43(env44, r41);
    return r40;
}

struct scm g2501(struct scm env2498, struct scm x, struct scm y) {
    struct scm r60;
    r60 = y;
    return r60;
}

struct scm g2500(struct scm env2498, struct scm x, struct scm y) {
    struct scm r61;
    r61 = x;
    return r61;
}

struct scm g2499(struct scm env2498, struct scm selector) {
    struct scm r62;
    struct scm r63;
    struct scm r64;
    struct scm r68;
    struct scm r69;
    struct scm r70;
    struct scm r71;
    struct scm clor65;
    clor65 = selector;
    r68 = env2498;
    r69 = (struct scm){ .tag = 0, .val.i = 1 };
    r63 = scm_vector_ref(r68, r69);
    r70 = env2498;
    r71 = (struct scm){ .tag = 0, .val.i = 0 };
    r64 = scm_vector_ref(r70, r71);
    scm_fptr clo66;
    struct scm env67;
    clo66 = clor65.val.v->elt[0].val.f;
    env67 = clor65.val.v->elt[1];
    r62 = clo66(env67, r63, r64);
    return r62;
}

