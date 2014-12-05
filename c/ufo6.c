#include "runtime.c"
struct scm scm_main(struct scm);
struct scm church_num(struct scm, struct scm);
struct scm begin(struct scm, struct scm, struct scm);
struct scm num_church(struct scm, struct scm);
struct scm zero(struct scm);
struct scm one(struct scm);
struct scm two(struct scm);
struct scm three(struct scm);
struct scm add(struct scm, struct scm, struct scm);
struct scm mul(struct scm, struct scm, struct scm);
struct scm g2508(struct scm, struct scm, struct scm);
struct scm g2507(struct scm, struct scm);
struct scm g2506(struct scm, struct scm, struct scm);
struct scm g2505(struct scm, struct scm, struct scm);
struct scm g2504(struct scm, struct scm, struct scm);
struct scm g2503(struct scm, struct scm, struct scm);
struct scm g2502(struct scm, struct scm, struct scm);
struct scm g2501(struct scm, struct scm, struct scm, struct scm);
struct scm g2500(struct scm, struct scm);
struct scm g2499(struct scm, struct scm);

struct scm scm_main(struct scm env2498) {
    struct scm r0;
    struct scm r1;
    struct scm r5;
    struct scm r9;
    struct scm r10;
    struct scm r14;
    struct scm r15;
    struct scm r25;
    struct scm clor2;
    clor2 = scm_wrap_fptr(scm_print);
    struct scm clor6;
    clor6 = scm_wrap_fptr(church_num);
    struct scm clor11;
    clor11 = scm_wrap_fptr(mul);
    struct scm clor16;
    clor16 = scm_wrap_fptr(add);
    struct scm clor19;
    clor19 = scm_wrap_fptr(three);
    scm_fptr clo20;
    struct scm env21;
    clo20 = clor19.val.v->elt[0].val.f;
    env21 = clor19.val.v->elt[1];
    r14 = clo20(env21);
    struct scm clor22;
    clor22 = scm_wrap_fptr(two);
    scm_fptr clo23;
    struct scm env24;
    clo23 = clor22.val.v->elt[0].val.f;
    env24 = clor22.val.v->elt[1];
    r15 = clo23(env24);
    scm_fptr clo17;
    struct scm env18;
    clo17 = clor16.val.v->elt[0].val.f;
    env18 = clor16.val.v->elt[1];
    r9 = clo17(env18, r14, r15);
    struct scm clor26;
    clor26 = scm_wrap_fptr(num_church);
    r25 = (struct scm){ .tag = 0, .val.i = 5 };
    scm_fptr clo27;
    struct scm env28;
    clo27 = clor26.val.v->elt[0].val.f;
    env28 = clor26.val.v->elt[1];
    r10 = clo27(env28, r25);
    scm_fptr clo12;
    struct scm env13;
    clo12 = clor11.val.v->elt[0].val.f;
    env13 = clor11.val.v->elt[1];
    r5 = clo12(env13, r9, r10);
    scm_fptr clo7;
    struct scm env8;
    clo7 = clor6.val.v->elt[0].val.f;
    env8 = clor6.val.v->elt[1];
    r1 = clo7(env8, r5);
    scm_fptr clo3;
    struct scm env4;
    clo3 = clor2.val.v->elt[0].val.f;
    env4 = clor2.val.v->elt[1];
    r0 = clo3(env4, r1);
    return r0;
}

struct scm church_num(struct scm env2498, struct scm n) {
    struct scm r29;
    struct scm r30;
    struct scm r31;
    struct scm r35;
    struct scm clor32;
    clor32 = n;
    r30 = (struct scm){ .tag = 0, .val.i = 0 };
    r35 = allocate_vector(0);
    r31 = make_closure(g2499, r35);
    scm_fptr clo33;
    struct scm env34;
    clo33 = clor32.val.v->elt[0].val.f;
    env34 = clor32.val.v->elt[1];
    r29 = clo33(env34, r30, r31);
    return r29;
}

struct scm begin(struct scm env2498, struct scm a, struct scm b) {
    struct scm r36;
    r36 = b;
    return r36;
}

struct scm num_church(struct scm env2498, struct scm n) {
    struct scm r37;
    struct scm r38;
    struct scm r42;
    struct scm r43;
    struct scm r44;
    struct scm clor39;
    r42 = allocate_vector(0);
    clor39 = make_closure(g2500, r42);
    r44 = n;
    r43 = allocate_vector(1);
    scm_vector_insert_bang(r43, r44, 0);
    r38 = make_closure(g2501, r43);
    scm_fptr clo40;
    struct scm env41;
    clo40 = clor39.val.v->elt[0].val.f;
    env41 = clor39.val.v->elt[1];
    r37 = clo40(env41, r38);
    return r37;
}

struct scm zero(struct scm env2498) {
    struct scm r45;
    struct scm r46;
    r46 = allocate_vector(0);
    r45 = make_closure(g2502, r46);
    return r45;
}

struct scm one(struct scm env2498) {
    struct scm r47;
    struct scm r48;
    r48 = allocate_vector(0);
    r47 = make_closure(g2503, r48);
    return r47;
}

struct scm two(struct scm env2498) {
    struct scm r49;
    struct scm r50;
    r50 = allocate_vector(0);
    r49 = make_closure(g2504, r50);
    return r49;
}

struct scm three(struct scm env2498) {
    struct scm r51;
    struct scm r52;
    r52 = allocate_vector(0);
    r51 = make_closure(g2505, r52);
    return r51;
}

struct scm add(struct scm env2498, struct scm x, struct scm y) {
    struct scm r53;
    struct scm r54;
    struct scm r55;
    struct scm r56;
    r55 = x;
    r56 = y;
    r54 = allocate_vector(2);
    scm_vector_insert_bang(r54, r55, 0);
    scm_vector_insert_bang(r54, r56, 1);
    r53 = make_closure(g2506, r54);
    return r53;
}

struct scm mul(struct scm env2498, struct scm x, struct scm y) {
    struct scm r57;
    struct scm r58;
    struct scm r59;
    struct scm r60;
    r59 = y;
    r60 = x;
    r58 = allocate_vector(2);
    scm_vector_insert_bang(r58, r59, 0);
    scm_vector_insert_bang(r58, r60, 1);
    r57 = make_closure(g2508, r58);
    return r57;
}

struct scm g2508(struct scm env2498, struct scm z, struct scm s) {
    struct scm r61;
    struct scm r62;
    struct scm r63;
    struct scm r67;
    struct scm r68;
    struct scm r69;
    struct scm r70;
    struct scm r71;
    struct scm r72;
    struct scm r73;
    struct scm clor64;
    r67 = env2498;
    r68 = (struct scm){ .tag = 0, .val.i = 1 };
    clor64 = scm_vector_ref(r67, r68);
    r62 = z;
    r70 = s;
    r72 = env2498;
    r73 = (struct scm){ .tag = 0, .val.i = 0 };
    r71 = scm_vector_ref(r72, r73);
    r69 = allocate_vector(2);
    scm_vector_insert_bang(r69, r70, 0);
    scm_vector_insert_bang(r69, r71, 1);
    r63 = make_closure(g2507, r69);
    scm_fptr clo65;
    struct scm env66;
    clo65 = clor64.val.v->elt[0].val.f;
    env66 = clor64.val.v->elt[1];
    r61 = clo65(env66, r62, r63);
    return r61;
}

struct scm g2507(struct scm env2498, struct scm z) {
    struct scm r74;
    struct scm r75;
    struct scm r76;
    struct scm r80;
    struct scm r81;
    struct scm r82;
    struct scm r83;
    struct scm clor77;
    r80 = env2498;
    r81 = (struct scm){ .tag = 0, .val.i = 1 };
    clor77 = scm_vector_ref(r80, r81);
    r75 = z;
    r82 = env2498;
    r83 = (struct scm){ .tag = 0, .val.i = 0 };
    r76 = scm_vector_ref(r82, r83);
    scm_fptr clo78;
    struct scm env79;
    clo78 = clor77.val.v->elt[0].val.f;
    env79 = clor77.val.v->elt[1];
    r74 = clo78(env79, r75, r76);
    return r74;
}

struct scm g2506(struct scm env2498, struct scm z, struct scm s) {
    struct scm r84;
    struct scm r85;
    struct scm r86;
    struct scm r90;
    struct scm r91;
    struct scm r92;
    struct scm r93;
    struct scm r97;
    struct scm r98;
    struct scm clor87;
    r90 = env2498;
    r91 = (struct scm){ .tag = 0, .val.i = 1 };
    clor87 = scm_vector_ref(r90, r91);
    struct scm clor94;
    r97 = env2498;
    r98 = (struct scm){ .tag = 0, .val.i = 0 };
    clor94 = scm_vector_ref(r97, r98);
    r92 = z;
    r93 = s;
    scm_fptr clo95;
    struct scm env96;
    clo95 = clor94.val.v->elt[0].val.f;
    env96 = clor94.val.v->elt[1];
    r85 = clo95(env96, r92, r93);
    r86 = s;
    scm_fptr clo88;
    struct scm env89;
    clo88 = clor87.val.v->elt[0].val.f;
    env89 = clor87.val.v->elt[1];
    r84 = clo88(env89, r85, r86);
    return r84;
}

struct scm g2505(struct scm env2498, struct scm z, struct scm s) {
    struct scm r99;
    struct scm r100;
    struct scm r104;
    struct scm r108;
    struct scm clor101;
    clor101 = s;
    struct scm clor105;
    clor105 = s;
    struct scm clor109;
    clor109 = s;
    r108 = z;
    scm_fptr clo110;
    struct scm env111;
    clo110 = clor109.val.v->elt[0].val.f;
    env111 = clor109.val.v->elt[1];
    r104 = clo110(env111, r108);
    scm_fptr clo106;
    struct scm env107;
    clo106 = clor105.val.v->elt[0].val.f;
    env107 = clor105.val.v->elt[1];
    r100 = clo106(env107, r104);
    scm_fptr clo102;
    struct scm env103;
    clo102 = clor101.val.v->elt[0].val.f;
    env103 = clor101.val.v->elt[1];
    r99 = clo102(env103, r100);
    return r99;
}

struct scm g2504(struct scm env2498, struct scm z, struct scm s) {
    struct scm r112;
    struct scm r113;
    struct scm r117;
    struct scm clor114;
    clor114 = s;
    struct scm clor118;
    clor118 = s;
    r117 = z;
    scm_fptr clo119;
    struct scm env120;
    clo119 = clor118.val.v->elt[0].val.f;
    env120 = clor118.val.v->elt[1];
    r113 = clo119(env120, r117);
    scm_fptr clo115;
    struct scm env116;
    clo115 = clor114.val.v->elt[0].val.f;
    env116 = clor114.val.v->elt[1];
    r112 = clo115(env116, r113);
    return r112;
}

struct scm g2503(struct scm env2498, struct scm z, struct scm s) {
    struct scm r121;
    struct scm r122;
    struct scm clor123;
    clor123 = s;
    r122 = z;
    scm_fptr clo124;
    struct scm env125;
    clo124 = clor123.val.v->elt[0].val.f;
    env125 = clor123.val.v->elt[1];
    r121 = clo124(env125, r122);
    return r121;
}

struct scm g2502(struct scm env2498, struct scm z, struct scm s) {
    struct scm r126;
    r126 = z;
    return r126;
}

struct scm g2501(struct scm env2498, struct scm f, struct scm i, struct scm c) {
    struct scm r127;
    struct scm r128;
    struct scm r129;
    struct scm r130;
    struct scm r134;
    struct scm r135;
    struct scm r136;
    struct scm r137;
    struct scm r138;
    struct scm r142;
    struct scm r143;
    struct scm r147;
    struct scm r148;
    struct scm clor131;
    clor131 = scm_wrap_fptr(scm_eq);
    r129 = i;
    r134 = env2498;
    r135 = (struct scm){ .tag = 0, .val.i = 0 };
    r130 = scm_vector_ref(r134, r135);
    scm_fptr clo132;
    struct scm env133;
    clo132 = clor131.val.v->elt[0].val.f;
    env133 = clor131.val.v->elt[1];
    r128 = clo132(env133, r129, r130);
    if (scm_extract_truth(r128)) {
        r127 = c;
    } else {
        struct scm clor139;
        clor139 = f;
        r136 = f;
        struct scm clor144;
        clor144 = scm_wrap_fptr(scm_plus);
        r142 = (struct scm){ .tag = 0, .val.i = 1 };
        r143 = i;
        scm_fptr clo145;
        struct scm env146;
        clo145 = clor144.val.v->elt[0].val.f;
        env146 = clor144.val.v->elt[1];
        r137 = clo145(env146, r142, r143);
        struct scm clor149;
        clor149 = scm_wrap_fptr(add);
        struct scm clor152;
        clor152 = scm_wrap_fptr(one);
        scm_fptr clo153;
        struct scm env154;
        clo153 = clor152.val.v->elt[0].val.f;
        env154 = clor152.val.v->elt[1];
        r147 = clo153(env154);
        r148 = c;
        scm_fptr clo150;
        struct scm env151;
        clo150 = clor149.val.v->elt[0].val.f;
        env151 = clor149.val.v->elt[1];
        r138 = clo150(env151, r147, r148);
        scm_fptr clo140;
        struct scm env141;
        clo140 = clor139.val.v->elt[0].val.f;
        env141 = clor139.val.v->elt[1];
        r127 = clo140(env141, r136, r137, r138);
    }
    return r127;
}

struct scm g2500(struct scm env2498, struct scm aux) {
    struct scm r155;
    struct scm r156;
    struct scm r157;
    struct scm r158;
    struct scm clor159;
    clor159 = aux;
    r156 = aux;
    r157 = (struct scm){ .tag = 0, .val.i = 0 };
    struct scm clor162;
    clor162 = scm_wrap_fptr(zero);
    scm_fptr clo163;
    struct scm env164;
    clo163 = clor162.val.v->elt[0].val.f;
    env164 = clor162.val.v->elt[1];
    r158 = clo163(env164);
    scm_fptr clo160;
    struct scm env161;
    clo160 = clor159.val.v->elt[0].val.f;
    env161 = clor159.val.v->elt[1];
    r155 = clo160(env161, r156, r157, r158);
    return r155;
}

struct scm g2499(struct scm env2498, struct scm i) {
    struct scm r165;
    struct scm r166;
    struct scm r167;
    struct scm clor168;
    clor168 = scm_wrap_fptr(scm_plus);
    r166 = (struct scm){ .tag = 0, .val.i = 1 };
    r167 = i;
    scm_fptr clo169;
    struct scm env170;
    clo169 = clor168.val.v->elt[0].val.f;
    env170 = clor168.val.v->elt[1];
    r165 = clo169(env170, r166, r167);
    return r165;
}

