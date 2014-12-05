#include "runtime.c"
struct scm cons(struct scm, struct scm, struct scm);
struct scm car(struct scm, struct scm);
struct scm cdr(struct scm, struct scm);
struct scm begin(struct scm, struct scm, struct scm);
struct scm print_each(struct scm, struct scm);
struct scm map(struct scm, struct scm, struct scm);
struct scm stuff(struct scm);
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
        r17 = (struct scm){ .tag = 0, .val.i = 0 };
    }
    return r17;
}

struct scm map(struct scm env2498, struct scm f, struct scm l) {
    struct scm r40;
    struct scm r41;
    struct scm r42;
    struct scm r43;
    struct scm r47;
    struct scm r51;
    struct scm r55;
    struct scm r56;
    struct scm r60;
    r41 = l;
    if (scm_extract_truth(r41)) {
        struct scm clor44;
        clor44 = scm_wrap_fptr(cons);
        struct scm clor48;
        clor48 = f;
        struct scm clor52;
        clor52 = scm_wrap_fptr(car);
        r51 = l;
        scm_fptr clo53;
        struct scm env54;
        clo53 = clor52.val.v->elt[0].val.f;
        env54 = clor52.val.v->elt[1];
        r47 = clo53(env54, r51);
        scm_fptr clo49;
        struct scm env50;
        clo49 = clor48.val.v->elt[0].val.f;
        env50 = clor48.val.v->elt[1];
        r42 = clo49(env50, r47);
        struct scm clor57;
        clor57 = scm_wrap_fptr(map);
        r55 = f;
        struct scm clor61;
        clor61 = scm_wrap_fptr(cdr);
        r60 = l;
        scm_fptr clo62;
        struct scm env63;
        clo62 = clor61.val.v->elt[0].val.f;
        env63 = clor61.val.v->elt[1];
        r56 = clo62(env63, r60);
        scm_fptr clo58;
        struct scm env59;
        clo58 = clor57.val.v->elt[0].val.f;
        env59 = clor57.val.v->elt[1];
        r43 = clo58(env59, r55, r56);
        scm_fptr clo45;
        struct scm env46;
        clo45 = clor44.val.v->elt[0].val.f;
        env46 = clor44.val.v->elt[1];
        r40 = clo45(env46, r42, r43);
    } else {
        r40 = (struct scm){ .tag = 0, .val.i = 0 };
    }
    return r40;
}

struct scm stuff(struct scm env2498) {
    struct scm r64;
    struct scm r65;
    struct scm r66;
    struct scm r70;
    struct scm r71;
    struct scm r75;
    struct scm r76;
    struct scm r80;
    struct scm r81;
    struct scm r85;
    struct scm r86;
    struct scm r90;
    struct scm r91;
    struct scm r95;
    struct scm r96;
    struct scm r100;
    struct scm r101;
    struct scm r105;
    struct scm r106;
    struct scm r110;
    struct scm r111;
    struct scm clor67;
    clor67 = scm_wrap_fptr(cons);
    struct scm clor72;
    clor72 = scm_wrap_fptr(cons);
    r70 = scm_string_to_vector("h");
    r71 = scm_string_to_vector("w");
    scm_fptr clo73;
    struct scm env74;
    clo73 = clor72.val.v->elt[0].val.f;
    env74 = clor72.val.v->elt[1];
    r65 = clo73(env74, r70, r71);
    struct scm clor77;
    clor77 = scm_wrap_fptr(cons);
    struct scm clor82;
    clor82 = scm_wrap_fptr(cons);
    r80 = scm_string_to_vector("e");
    r81 = scm_string_to_vector("o");
    scm_fptr clo83;
    struct scm env84;
    clo83 = clor82.val.v->elt[0].val.f;
    env84 = clor82.val.v->elt[1];
    r75 = clo83(env84, r80, r81);
    struct scm clor87;
    clor87 = scm_wrap_fptr(cons);
    struct scm clor92;
    clor92 = scm_wrap_fptr(cons);
    r90 = scm_string_to_vector("l");
    r91 = scm_string_to_vector("r");
    scm_fptr clo93;
    struct scm env94;
    clo93 = clor92.val.v->elt[0].val.f;
    env94 = clor92.val.v->elt[1];
    r85 = clo93(env94, r90, r91);
    struct scm clor97;
    clor97 = scm_wrap_fptr(cons);
    struct scm clor102;
    clor102 = scm_wrap_fptr(cons);
    r100 = scm_string_to_vector("l");
    r101 = scm_string_to_vector("l");
    scm_fptr clo103;
    struct scm env104;
    clo103 = clor102.val.v->elt[0].val.f;
    env104 = clor102.val.v->elt[1];
    r95 = clo103(env104, r100, r101);
    struct scm clor107;
    clor107 = scm_wrap_fptr(cons);
    struct scm clor112;
    clor112 = scm_wrap_fptr(cons);
    r110 = scm_string_to_vector("o");
    r111 = scm_string_to_vector("d");
    scm_fptr clo113;
    struct scm env114;
    clo113 = clor112.val.v->elt[0].val.f;
    env114 = clor112.val.v->elt[1];
    r105 = clo113(env114, r110, r111);
    r106 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo108;
    struct scm env109;
    clo108 = clor107.val.v->elt[0].val.f;
    env109 = clor107.val.v->elt[1];
    r96 = clo108(env109, r105, r106);
    scm_fptr clo98;
    struct scm env99;
    clo98 = clor97.val.v->elt[0].val.f;
    env99 = clor97.val.v->elt[1];
    r86 = clo98(env99, r95, r96);
    scm_fptr clo88;
    struct scm env89;
    clo88 = clor87.val.v->elt[0].val.f;
    env89 = clor87.val.v->elt[1];
    r76 = clo88(env89, r85, r86);
    scm_fptr clo78;
    struct scm env79;
    clo78 = clor77.val.v->elt[0].val.f;
    env79 = clor77.val.v->elt[1];
    r66 = clo78(env79, r75, r76);
    scm_fptr clo68;
    struct scm env69;
    clo68 = clor67.val.v->elt[0].val.f;
    env69 = clor67.val.v->elt[1];
    r64 = clo68(env69, r65, r66);
    return r64;
}

struct scm scm_main(struct scm env2498) {
    struct scm r115;
    struct scm r116;
    struct scm r117;
    struct scm r121;
    struct scm r125;
    struct scm r126;
    struct scm r133;
    struct scm r137;
    struct scm r138;
    struct scm clor118;
    clor118 = scm_wrap_fptr(begin);
    struct scm clor122;
    clor122 = scm_wrap_fptr(print_each);
    struct scm clor127;
    clor127 = scm_wrap_fptr(map);
    r125 = scm_wrap_fptr(car);
    struct scm clor130;
    clor130 = scm_wrap_fptr(stuff);
    scm_fptr clo131;
    struct scm env132;
    clo131 = clor130.val.v->elt[0].val.f;
    env132 = clor130.val.v->elt[1];
    r126 = clo131(env132);
    scm_fptr clo128;
    struct scm env129;
    clo128 = clor127.val.v->elt[0].val.f;
    env129 = clor127.val.v->elt[1];
    r121 = clo128(env129, r125, r126);
    scm_fptr clo123;
    struct scm env124;
    clo123 = clor122.val.v->elt[0].val.f;
    env124 = clor122.val.v->elt[1];
    r116 = clo123(env124, r121);
    struct scm clor134;
    clor134 = scm_wrap_fptr(print_each);
    struct scm clor139;
    clor139 = scm_wrap_fptr(map);
    r137 = scm_wrap_fptr(cdr);
    struct scm clor142;
    clor142 = scm_wrap_fptr(stuff);
    scm_fptr clo143;
    struct scm env144;
    clo143 = clor142.val.v->elt[0].val.f;
    env144 = clor142.val.v->elt[1];
    r138 = clo143(env144);
    scm_fptr clo140;
    struct scm env141;
    clo140 = clor139.val.v->elt[0].val.f;
    env141 = clor139.val.v->elt[1];
    r133 = clo140(env141, r137, r138);
    scm_fptr clo135;
    struct scm env136;
    clo135 = clor134.val.v->elt[0].val.f;
    env136 = clor134.val.v->elt[1];
    r117 = clo135(env136, r133);
    scm_fptr clo119;
    struct scm env120;
    clo119 = clor118.val.v->elt[0].val.f;
    env120 = clor118.val.v->elt[1];
    r115 = clo119(env120, r116, r117);
    return r115;
}

struct scm g2501(struct scm env2498, struct scm x, struct scm y) {
    struct scm r145;
    r145 = y;
    return r145;
}

struct scm g2500(struct scm env2498, struct scm x, struct scm y) {
    struct scm r146;
    r146 = x;
    return r146;
}

struct scm g2499(struct scm env2498, struct scm selector) {
    struct scm r147;
    struct scm r148;
    struct scm r149;
    struct scm r153;
    struct scm r154;
    struct scm r155;
    struct scm r156;
    struct scm clor150;
    clor150 = selector;
    r153 = env2498;
    r154 = (struct scm){ .tag = 0, .val.i = 1 };
    r148 = scm_vector_ref(r153, r154);
    r155 = env2498;
    r156 = (struct scm){ .tag = 0, .val.i = 0 };
    r149 = scm_vector_ref(r155, r156);
    scm_fptr clo151;
    struct scm env152;
    clo151 = clor150.val.v->elt[0].val.f;
    env152 = clor150.val.v->elt[1];
    r147 = clo151(env152, r148, r149);
    return r147;
}

