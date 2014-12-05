#include "runtime.c"
struct scm cons(struct scm, struct scm, struct scm);
struct scm car(struct scm, struct scm);
struct scm cdr(struct scm, struct scm);
struct scm input(struct scm);
struct scm match(struct scm, struct scm, struct scm);
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

struct scm input(struct scm env2498) {
    struct scm r16;
    struct scm r17;
    struct scm r18;
    struct scm r22;
    struct scm r23;
    struct scm r27;
    struct scm r28;
    struct scm r32;
    struct scm r33;
    struct scm r37;
    struct scm r38;
    struct scm r42;
    struct scm r43;
    struct scm r47;
    struct scm r48;
    struct scm r52;
    struct scm r53;
    struct scm r57;
    struct scm r58;
    struct scm r62;
    struct scm r63;
    struct scm r67;
    struct scm r68;
    struct scm r72;
    struct scm r73;
    struct scm r77;
    struct scm r78;
    struct scm r82;
    struct scm r83;
    struct scm r87;
    struct scm r88;
    struct scm r92;
    struct scm r93;
    struct scm r97;
    struct scm r98;
    struct scm r102;
    struct scm r103;
    struct scm clor19;
    clor19 = scm_wrap_fptr(cons);
    r17 = (struct scm){ .tag = 0, .val.i = 0 };
    struct scm clor24;
    clor24 = scm_wrap_fptr(cons);
    r22 = (struct scm){ .tag = 0, .val.i = 0 };
    struct scm clor29;
    clor29 = scm_wrap_fptr(cons);
    r27 = (struct scm){ .tag = 0, .val.i = 0 };
    struct scm clor34;
    clor34 = scm_wrap_fptr(cons);
    r32 = (struct scm){ .tag = 0, .val.i = 1 };
    struct scm clor39;
    clor39 = scm_wrap_fptr(cons);
    r37 = (struct scm){ .tag = 0, .val.i = 1 };
    struct scm clor44;
    clor44 = scm_wrap_fptr(cons);
    r42 = (struct scm){ .tag = 0, .val.i = 0 };
    struct scm clor49;
    clor49 = scm_wrap_fptr(cons);
    r47 = (struct scm){ .tag = 0, .val.i = 1 };
    struct scm clor54;
    clor54 = scm_wrap_fptr(cons);
    r52 = (struct scm){ .tag = 0, .val.i = 0 };
    struct scm clor59;
    clor59 = scm_wrap_fptr(cons);
    r57 = (struct scm){ .tag = 0, .val.i = 0 };
    struct scm clor64;
    clor64 = scm_wrap_fptr(cons);
    r62 = (struct scm){ .tag = 0, .val.i = 1 };
    struct scm clor69;
    clor69 = scm_wrap_fptr(cons);
    r67 = (struct scm){ .tag = 0, .val.i = 0 };
    struct scm clor74;
    clor74 = scm_wrap_fptr(cons);
    r72 = (struct scm){ .tag = 0, .val.i = 1 };
    struct scm clor79;
    clor79 = scm_wrap_fptr(cons);
    r77 = (struct scm){ .tag = 0, .val.i = 0 };
    struct scm clor84;
    clor84 = scm_wrap_fptr(cons);
    r82 = (struct scm){ .tag = 0, .val.i = 1 };
    struct scm clor89;
    clor89 = scm_wrap_fptr(cons);
    r87 = (struct scm){ .tag = 0, .val.i = 1 };
    struct scm clor94;
    clor94 = scm_wrap_fptr(cons);
    r92 = (struct scm){ .tag = 0, .val.i = 0 };
    struct scm clor99;
    clor99 = scm_wrap_fptr(cons);
    r97 = (struct scm){ .tag = 0, .val.i = 1 };
    struct scm clor104;
    clor104 = scm_wrap_fptr(cons);
    r102 = (struct scm){ .tag = 0, .val.i = 1 };
    r103 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo105;
    struct scm env106;
    clo105 = clor104.val.v->elt[0].val.f;
    env106 = clor104.val.v->elt[1];
    r98 = clo105(env106, r102, r103);
    scm_fptr clo100;
    struct scm env101;
    clo100 = clor99.val.v->elt[0].val.f;
    env101 = clor99.val.v->elt[1];
    r93 = clo100(env101, r97, r98);
    scm_fptr clo95;
    struct scm env96;
    clo95 = clor94.val.v->elt[0].val.f;
    env96 = clor94.val.v->elt[1];
    r88 = clo95(env96, r92, r93);
    scm_fptr clo90;
    struct scm env91;
    clo90 = clor89.val.v->elt[0].val.f;
    env91 = clor89.val.v->elt[1];
    r83 = clo90(env91, r87, r88);
    scm_fptr clo85;
    struct scm env86;
    clo85 = clor84.val.v->elt[0].val.f;
    env86 = clor84.val.v->elt[1];
    r78 = clo85(env86, r82, r83);
    scm_fptr clo80;
    struct scm env81;
    clo80 = clor79.val.v->elt[0].val.f;
    env81 = clor79.val.v->elt[1];
    r73 = clo80(env81, r77, r78);
    scm_fptr clo75;
    struct scm env76;
    clo75 = clor74.val.v->elt[0].val.f;
    env76 = clor74.val.v->elt[1];
    r68 = clo75(env76, r72, r73);
    scm_fptr clo70;
    struct scm env71;
    clo70 = clor69.val.v->elt[0].val.f;
    env71 = clor69.val.v->elt[1];
    r63 = clo70(env71, r67, r68);
    scm_fptr clo65;
    struct scm env66;
    clo65 = clor64.val.v->elt[0].val.f;
    env66 = clor64.val.v->elt[1];
    r58 = clo65(env66, r62, r63);
    scm_fptr clo60;
    struct scm env61;
    clo60 = clor59.val.v->elt[0].val.f;
    env61 = clor59.val.v->elt[1];
    r53 = clo60(env61, r57, r58);
    scm_fptr clo55;
    struct scm env56;
    clo55 = clor54.val.v->elt[0].val.f;
    env56 = clor54.val.v->elt[1];
    r48 = clo55(env56, r52, r53);
    scm_fptr clo50;
    struct scm env51;
    clo50 = clor49.val.v->elt[0].val.f;
    env51 = clor49.val.v->elt[1];
    r43 = clo50(env51, r47, r48);
    scm_fptr clo45;
    struct scm env46;
    clo45 = clor44.val.v->elt[0].val.f;
    env46 = clor44.val.v->elt[1];
    r38 = clo45(env46, r42, r43);
    scm_fptr clo40;
    struct scm env41;
    clo40 = clor39.val.v->elt[0].val.f;
    env41 = clor39.val.v->elt[1];
    r33 = clo40(env41, r37, r38);
    scm_fptr clo35;
    struct scm env36;
    clo35 = clor34.val.v->elt[0].val.f;
    env36 = clor34.val.v->elt[1];
    r28 = clo35(env36, r32, r33);
    scm_fptr clo30;
    struct scm env31;
    clo30 = clor29.val.v->elt[0].val.f;
    env31 = clor29.val.v->elt[1];
    r23 = clo30(env31, r27, r28);
    scm_fptr clo25;
    struct scm env26;
    clo25 = clor24.val.v->elt[0].val.f;
    env26 = clor24.val.v->elt[1];
    r18 = clo25(env26, r22, r23);
    scm_fptr clo20;
    struct scm env21;
    clo20 = clor19.val.v->elt[0].val.f;
    env21 = clor19.val.v->elt[1];
    r16 = clo20(env21, r17, r18);
    return r16;
}

struct scm match(struct scm env2498, struct scm stack, struct scm l) {
    struct scm r107;
    struct scm r108;
    struct scm r109;
    struct scm r110;
    struct scm r114;
    struct scm r115;
    struct scm r116;
    struct scm r120;
    struct scm r124;
    struct scm r128;
    struct scm r132;
    struct scm r133;
    struct scm r137;
    struct scm r138;
    struct scm r142;
    struct scm r146;
    struct scm r147;
    struct scm r151;
    r108 = l;
    if (scm_extract_truth(r108)) {
        struct scm clor111;
        clor111 = scm_wrap_fptr(car);
        r110 = l;
        scm_fptr clo112;
        struct scm env113;
        clo112 = clor111.val.v->elt[0].val.f;
        env113 = clor111.val.v->elt[1];
        r109 = clo112(env113, r110);
        if (scm_extract_truth(r109)) {
            r114 = stack;
            if (scm_extract_truth(r114)) {
                struct scm clor117;
                clor117 = scm_wrap_fptr(match);
                struct scm clor121;
                clor121 = scm_wrap_fptr(cdr);
                r120 = stack;
                scm_fptr clo122;
                struct scm env123;
                clo122 = clor121.val.v->elt[0].val.f;
                env123 = clor121.val.v->elt[1];
                r115 = clo122(env123, r120);
                struct scm clor125;
                clor125 = scm_wrap_fptr(cdr);
                r124 = l;
                scm_fptr clo126;
                struct scm env127;
                clo126 = clor125.val.v->elt[0].val.f;
                env127 = clor125.val.v->elt[1];
                r116 = clo126(env127, r124);
                scm_fptr clo118;
                struct scm env119;
                clo118 = clor117.val.v->elt[0].val.f;
                env119 = clor117.val.v->elt[1];
                r107 = clo118(env119, r115, r116);
            } else {
                struct scm clor129;
                clor129 = scm_wrap_fptr(scm_print);
                r128 = scm_string_to_vector("too many closes fail");
                scm_fptr clo130;
                struct scm env131;
                clo130 = clor129.val.v->elt[0].val.f;
                env131 = clor129.val.v->elt[1];
                r107 = clo130(env131, r128);
            }
        } else {
            struct scm clor134;
            clor134 = scm_wrap_fptr(match);
            struct scm clor139;
            clor139 = scm_wrap_fptr(cons);
            r137 = (struct scm){ .tag = 0, .val.i = 0 };
            r138 = stack;
            scm_fptr clo140;
            struct scm env141;
            clo140 = clor139.val.v->elt[0].val.f;
            env141 = clor139.val.v->elt[1];
            r132 = clo140(env141, r137, r138);
            struct scm clor143;
            clor143 = scm_wrap_fptr(cdr);
            r142 = l;
            scm_fptr clo144;
            struct scm env145;
            clo144 = clor143.val.v->elt[0].val.f;
            env145 = clor143.val.v->elt[1];
            r133 = clo144(env145, r142);
            scm_fptr clo135;
            struct scm env136;
            clo135 = clor134.val.v->elt[0].val.f;
            env136 = clor134.val.v->elt[1];
            r107 = clo135(env136, r132, r133);
        }
    } else {
        r146 = stack;
        if (scm_extract_truth(r146)) {
            struct scm clor148;
            clor148 = scm_wrap_fptr(scm_print);
            r147 = scm_string_to_vector("too many opens fail");
            scm_fptr clo149;
            struct scm env150;
            clo149 = clor148.val.v->elt[0].val.f;
            env150 = clor148.val.v->elt[1];
            r107 = clo149(env150, r147);
        } else {
            struct scm clor152;
            clor152 = scm_wrap_fptr(scm_print);
            r151 = scm_string_to_vector("We did it!");
            scm_fptr clo153;
            struct scm env154;
            clo153 = clor152.val.v->elt[0].val.f;
            env154 = clor152.val.v->elt[1];
            r107 = clo153(env154, r151);
        }
    }
    return r107;
}

struct scm scm_main(struct scm env2498) {
    struct scm r155;
    struct scm r156;
    struct scm r157;
    struct scm clor158;
    clor158 = scm_wrap_fptr(match);
    r156 = (struct scm){ .tag = 0, .val.i = 0 };
    struct scm clor161;
    clor161 = scm_wrap_fptr(input);
    scm_fptr clo162;
    struct scm env163;
    clo162 = clor161.val.v->elt[0].val.f;
    env163 = clor161.val.v->elt[1];
    r157 = clo162(env163);
    scm_fptr clo159;
    struct scm env160;
    clo159 = clor158.val.v->elt[0].val.f;
    env160 = clor158.val.v->elt[1];
    r155 = clo159(env160, r156, r157);
    return r155;
}

struct scm g2501(struct scm env2498, struct scm x, struct scm y) {
    struct scm r164;
    r164 = y;
    return r164;
}

struct scm g2500(struct scm env2498, struct scm x, struct scm y) {
    struct scm r165;
    r165 = x;
    return r165;
}

struct scm g2499(struct scm env2498, struct scm selector) {
    struct scm r166;
    struct scm r167;
    struct scm r168;
    struct scm r172;
    struct scm r173;
    struct scm r174;
    struct scm r175;
    struct scm clor169;
    clor169 = selector;
    r172 = env2498;
    r173 = (struct scm){ .tag = 0, .val.i = 1 };
    r167 = scm_vector_ref(r172, r173);
    r174 = env2498;
    r175 = (struct scm){ .tag = 0, .val.i = 0 };
    r168 = scm_vector_ref(r174, r175);
    scm_fptr clo170;
    struct scm env171;
    clo170 = clor169.val.v->elt[0].val.f;
    env171 = clor169.val.v->elt[1];
    r166 = clo170(env171, r167, r168);
    return r166;
}

