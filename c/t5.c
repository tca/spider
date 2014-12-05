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
    struct scm r16;
    struct scm clor12;
    clor12 = c;
    r16 = c;
    r15 = allocate_vector(1);
    scm_vector_insert_bang(r15, r16, 0);
    r11 = make_closure(g2501, r15);
    scm_fptr clo13;
    struct scm env14;
    clo13 = clor12.val.v->elt[0].val.f;
    env14 = clor12.val.v->elt[1];
    r10 = clo13(env14, r11);
    return r10;
}

struct scm begin(struct scm env2498, struct scm x, struct scm y) {
    struct scm r17;
    r17 = y;
    return r17;
}

struct scm print_each(struct scm env2498, struct scm list) {
    struct scm r18;
    struct scm r19;
    struct scm r20;
    struct scm r21;
    struct scm r25;
    struct scm r29;
    struct scm r33;
    struct scm r37;
    r19 = list;
    if (scm_extract_truth(r19)) {
        struct scm clor22;
        clor22 = scm_wrap_fptr(begin);
        struct scm clor26;
        clor26 = scm_wrap_fptr(scm_print);
        struct scm clor30;
        clor30 = scm_wrap_fptr(car);
        r29 = list;
        scm_fptr clo31;
        struct scm env32;
        clo31 = clor30.val.v->elt[0].val.f;
        env32 = clor30.val.v->elt[1];
        r25 = clo31(env32, r29);
        scm_fptr clo27;
        struct scm env28;
        clo27 = clor26.val.v->elt[0].val.f;
        env28 = clor26.val.v->elt[1];
        r20 = clo27(env28, r25);
        struct scm clor34;
        clor34 = scm_wrap_fptr(print_each);
        struct scm clor38;
        clor38 = scm_wrap_fptr(cdr);
        r37 = list;
        scm_fptr clo39;
        struct scm env40;
        clo39 = clor38.val.v->elt[0].val.f;
        env40 = clor38.val.v->elt[1];
        r33 = clo39(env40, r37);
        scm_fptr clo35;
        struct scm env36;
        clo35 = clor34.val.v->elt[0].val.f;
        env36 = clor34.val.v->elt[1];
        r21 = clo35(env36, r33);
        scm_fptr clo23;
        struct scm env24;
        clo23 = clor22.val.v->elt[0].val.f;
        env24 = clor22.val.v->elt[1];
        r18 = clo23(env24, r20, r21);
    } else {
        struct scm clor22;
        clor22 = scm_wrap_fptr(begin);
        struct scm clor26;
        clor26 = scm_wrap_fptr(scm_print);
        struct scm clor30;
        clor30 = scm_wrap_fptr(car);
        r29 = list;
        scm_fptr clo31;
        struct scm env32;
        clo31 = clor30.val.v->elt[0].val.f;
        env32 = clor30.val.v->elt[1];
        r25 = clo31(env32, r29);
        scm_fptr clo27;
        struct scm env28;
        clo27 = clor26.val.v->elt[0].val.f;
        env28 = clor26.val.v->elt[1];
        r20 = clo27(env28, r25);
        struct scm clor34;
        clor34 = scm_wrap_fptr(print_each);
        struct scm clor38;
        clor38 = scm_wrap_fptr(cdr);
        r37 = list;
        scm_fptr clo39;
        struct scm env40;
        clo39 = clor38.val.v->elt[0].val.f;
        env40 = clor38.val.v->elt[1];
        r33 = clo39(env40, r37);
        scm_fptr clo35;
        struct scm env36;
        clo35 = clor34.val.v->elt[0].val.f;
        env36 = clor34.val.v->elt[1];
        r21 = clo35(env36, r33);
        scm_fptr clo23;
        struct scm env24;
        clo23 = clor22.val.v->elt[0].val.f;
        env24 = clor22.val.v->elt[1];
        r18 = clo23(env24, r20, r21);
    }
    return r18;
}

struct scm scm_main(struct scm env2498) {
    struct scm r41;
    struct scm r42;
    struct scm r46;
    struct scm r47;
    struct scm r51;
    struct scm r52;
    struct scm r56;
    struct scm r57;
    struct scm clor43;
    clor43 = scm_wrap_fptr(print_each);
    struct scm clor48;
    clor48 = scm_wrap_fptr(cons);
    r46 = scm_string_to_vector("Hello");
    struct scm clor53;
    clor53 = scm_wrap_fptr(cons);
    r51 = scm_string_to_vector("World");
    struct scm clor58;
    clor58 = scm_wrap_fptr(cons);
    r56 = scm_string_to_vector("!");
    r57 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo59;
    struct scm env60;
    clo59 = clor58.val.v->elt[0].val.f;
    env60 = clor58.val.v->elt[1];
    r52 = clo59(env60, r56, r57);
    scm_fptr clo54;
    struct scm env55;
    clo54 = clor53.val.v->elt[0].val.f;
    env55 = clor53.val.v->elt[1];
    r47 = clo54(env55, r51, r52);
    scm_fptr clo49;
    struct scm env50;
    clo49 = clor48.val.v->elt[0].val.f;
    env50 = clor48.val.v->elt[1];
    r42 = clo49(env50, r46, r47);
    scm_fptr clo44;
    struct scm env45;
    clo44 = clor43.val.v->elt[0].val.f;
    env45 = clor43.val.v->elt[1];
    r41 = clo44(env45, r42);
    return r41;
}

struct scm g2501(struct scm env2498, struct scm x, struct scm y) {
    struct scm r61;
    struct scm r62;
    struct scm r63;
    r62 = env2498;
    r63 = (struct scm){ .tag = 0, .val.i = 0 };
    r61 = scm_vector_ref(r62, r63);
    return r61;
}

struct scm g2500(struct scm env2498, struct scm x, struct scm y) {
    struct scm r64;
    r64 = x;
    return r64;
}

struct scm g2499(struct scm env2498, struct scm selector) {
    struct scm r65;
    struct scm r66;
    struct scm r67;
    struct scm r71;
    struct scm r72;
    struct scm r73;
    struct scm r74;
    struct scm clor68;
    clor68 = selector;
    r71 = env2498;
    r72 = (struct scm){ .tag = 0, .val.i = 1 };
    r66 = scm_vector_ref(r71, r72);
    r73 = env2498;
    r74 = (struct scm){ .tag = 0, .val.i = 0 };
    r67 = scm_vector_ref(r73, r74);
    scm_fptr clo69;
    struct scm env70;
    clo69 = clor68.val.v->elt[0].val.f;
    env70 = clor68.val.v->elt[1];
    r65 = clo69(env70, r66, r67);
    return r65;
}

