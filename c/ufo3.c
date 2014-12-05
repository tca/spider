#include "runtime.c"
struct scm scm_main(struct scm);
struct scm one(struct scm);
struct scm two(struct scm);
struct scm three(struct scm);
struct scm add(struct scm, struct scm, struct scm);
struct scm mul(struct scm, struct scm, struct scm);
struct scm g2505(struct scm, struct scm, struct scm);
struct scm g2504(struct scm, struct scm);
struct scm g2503(struct scm, struct scm, struct scm);
struct scm g2502(struct scm, struct scm, struct scm);
struct scm g2501(struct scm, struct scm, struct scm);
struct scm g2500(struct scm, struct scm, struct scm);
struct scm g2499(struct scm, struct scm);

struct scm scm_main(struct scm env2498) {
    struct scm r0;
    struct scm r1;
    struct scm r2;
    struct scm r6;
    struct scm r7;
    struct scm r11;
    struct scm r12;
    struct scm r25;
    struct scm clor3;
    struct scm clor8;
    clor8 = scm_wrap_fptr(mul);
    struct scm clor13;
    clor13 = scm_wrap_fptr(add);
    struct scm clor16;
    clor16 = scm_wrap_fptr(three);
    scm_fptr clo17;
    struct scm env18;
    clo17 = clor16.val.v->elt[0].val.f;
    env18 = clor16.val.v->elt[1];
    r11 = clo17(env18);
    struct scm clor19;
    clor19 = scm_wrap_fptr(two);
    scm_fptr clo20;
    struct scm env21;
    clo20 = clor19.val.v->elt[0].val.f;
    env21 = clor19.val.v->elt[1];
    r12 = clo20(env21);
    scm_fptr clo14;
    struct scm env15;
    clo14 = clor13.val.v->elt[0].val.f;
    env15 = clor13.val.v->elt[1];
    r6 = clo14(env15, r11, r12);
    struct scm clor22;
    clor22 = scm_wrap_fptr(three);
    scm_fptr clo23;
    struct scm env24;
    clo23 = clor22.val.v->elt[0].val.f;
    env24 = clor22.val.v->elt[1];
    r7 = clo23(env24);
    scm_fptr clo9;
    struct scm env10;
    clo9 = clor8.val.v->elt[0].val.f;
    env10 = clor8.val.v->elt[1];
    clor3 = clo9(env10, r6, r7);
    r1 = (struct scm){ .tag = 0, .val.i = 0 };
    r25 = allocate_vector(0);
    r2 = make_closure(g2499, r25);
    scm_fptr clo4;
    struct scm env5;
    clo4 = clor3.val.v->elt[0].val.f;
    env5 = clor3.val.v->elt[1];
    r0 = clo4(env5, r1, r2);
    return r0;
}

struct scm one(struct scm env2498) {
    struct scm r26;
    struct scm r27;
    r27 = allocate_vector(0);
    r26 = make_closure(g2500, r27);
    return r26;
}

struct scm two(struct scm env2498) {
    struct scm r28;
    struct scm r29;
    r29 = allocate_vector(0);
    r28 = make_closure(g2501, r29);
    return r28;
}

struct scm three(struct scm env2498) {
    struct scm r30;
    struct scm r31;
    r31 = allocate_vector(0);
    r30 = make_closure(g2502, r31);
    return r30;
}

struct scm add(struct scm env2498, struct scm x, struct scm y) {
    struct scm r32;
    struct scm r33;
    struct scm r34;
    struct scm r35;
    r34 = x;
    r35 = y;
    r33 = allocate_vector(2);
    scm_vector_insert_bang(r33, r34, 0);
    scm_vector_insert_bang(r33, r35, 1);
    r32 = make_closure(g2503, r33);
    return r32;
}

struct scm mul(struct scm env2498, struct scm x, struct scm y) {
    struct scm r36;
    struct scm r37;
    struct scm r38;
    struct scm r39;
    r38 = y;
    r39 = x;
    r37 = allocate_vector(2);
    scm_vector_insert_bang(r37, r38, 0);
    scm_vector_insert_bang(r37, r39, 1);
    r36 = make_closure(g2505, r37);
    return r36;
}

struct scm g2505(struct scm env2498, struct scm z, struct scm s) {
    struct scm r40;
    struct scm r41;
    struct scm r42;
    struct scm r46;
    struct scm r47;
    struct scm r48;
    struct scm r49;
    struct scm r50;
    struct scm r51;
    struct scm r52;
    struct scm clor43;
    r46 = env2498;
    r47 = (struct scm){ .tag = 0, .val.i = 1 };
    clor43 = scm_vector_ref(r46, r47);
    r41 = z;
    r49 = s;
    r51 = env2498;
    r52 = (struct scm){ .tag = 0, .val.i = 0 };
    r50 = scm_vector_ref(r51, r52);
    r48 = allocate_vector(2);
    scm_vector_insert_bang(r48, r49, 0);
    scm_vector_insert_bang(r48, r50, 1);
    r42 = make_closure(g2504, r48);
    scm_fptr clo44;
    struct scm env45;
    clo44 = clor43.val.v->elt[0].val.f;
    env45 = clor43.val.v->elt[1];
    r40 = clo44(env45, r41, r42);
    return r40;
}

struct scm g2504(struct scm env2498, struct scm z) {
    struct scm r53;
    struct scm r54;
    struct scm r55;
    struct scm r59;
    struct scm r60;
    struct scm r61;
    struct scm r62;
    struct scm clor56;
    r59 = env2498;
    r60 = (struct scm){ .tag = 0, .val.i = 1 };
    clor56 = scm_vector_ref(r59, r60);
    r54 = z;
    r61 = env2498;
    r62 = (struct scm){ .tag = 0, .val.i = 0 };
    r55 = scm_vector_ref(r61, r62);
    scm_fptr clo57;
    struct scm env58;
    clo57 = clor56.val.v->elt[0].val.f;
    env58 = clor56.val.v->elt[1];
    r53 = clo57(env58, r54, r55);
    return r53;
}

struct scm g2503(struct scm env2498, struct scm z, struct scm s) {
    struct scm r63;
    struct scm r64;
    struct scm r65;
    struct scm r69;
    struct scm r70;
    struct scm r71;
    struct scm r72;
    struct scm r76;
    struct scm r77;
    struct scm clor66;
    r69 = env2498;
    r70 = (struct scm){ .tag = 0, .val.i = 1 };
    clor66 = scm_vector_ref(r69, r70);
    struct scm clor73;
    r76 = env2498;
    r77 = (struct scm){ .tag = 0, .val.i = 0 };
    clor73 = scm_vector_ref(r76, r77);
    r71 = z;
    r72 = s;
    scm_fptr clo74;
    struct scm env75;
    clo74 = clor73.val.v->elt[0].val.f;
    env75 = clor73.val.v->elt[1];
    r64 = clo74(env75, r71, r72);
    r65 = s;
    scm_fptr clo67;
    struct scm env68;
    clo67 = clor66.val.v->elt[0].val.f;
    env68 = clor66.val.v->elt[1];
    r63 = clo67(env68, r64, r65);
    return r63;
}

struct scm g2502(struct scm env2498, struct scm z, struct scm s) {
    struct scm r78;
    struct scm r79;
    struct scm r83;
    struct scm r87;
    struct scm clor80;
    clor80 = s;
    struct scm clor84;
    clor84 = s;
    struct scm clor88;
    clor88 = s;
    r87 = z;
    scm_fptr clo89;
    struct scm env90;
    clo89 = clor88.val.v->elt[0].val.f;
    env90 = clor88.val.v->elt[1];
    r83 = clo89(env90, r87);
    scm_fptr clo85;
    struct scm env86;
    clo85 = clor84.val.v->elt[0].val.f;
    env86 = clor84.val.v->elt[1];
    r79 = clo85(env86, r83);
    scm_fptr clo81;
    struct scm env82;
    clo81 = clor80.val.v->elt[0].val.f;
    env82 = clor80.val.v->elt[1];
    r78 = clo81(env82, r79);
    return r78;
}

struct scm g2501(struct scm env2498, struct scm z, struct scm s) {
    struct scm r91;
    struct scm r92;
    struct scm r96;
    struct scm clor93;
    clor93 = s;
    struct scm clor97;
    clor97 = s;
    r96 = z;
    scm_fptr clo98;
    struct scm env99;
    clo98 = clor97.val.v->elt[0].val.f;
    env99 = clor97.val.v->elt[1];
    r92 = clo98(env99, r96);
    scm_fptr clo94;
    struct scm env95;
    clo94 = clor93.val.v->elt[0].val.f;
    env95 = clor93.val.v->elt[1];
    r91 = clo94(env95, r92);
    return r91;
}

struct scm g2500(struct scm env2498, struct scm z, struct scm s) {
    struct scm r100;
    struct scm r101;
    struct scm clor102;
    clor102 = s;
    r101 = z;
    scm_fptr clo103;
    struct scm env104;
    clo103 = clor102.val.v->elt[0].val.f;
    env104 = clor102.val.v->elt[1];
    r100 = clo103(env104, r101);
    return r100;
}

struct scm g2499(struct scm env2498, struct scm i) {
    struct scm r105;
    struct scm r106;
    struct scm clor107;
    clor107 = scm_wrap_fptr(scm_print);
    r106 = scm_string_to_vector("i");
    scm_fptr clo108;
    struct scm env109;
    clo108 = clor107.val.v->elt[0].val.f;
    env109 = clor107.val.v->elt[1];
    r105 = clo108(env109, r106);
    return r105;
}

