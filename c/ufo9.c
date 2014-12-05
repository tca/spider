#include "runtime.c"
struct scm cons(struct scm, struct scm, struct scm);
struct scm car(struct scm, struct scm);
struct scm cdr(struct scm, struct scm);
struct scm begin(struct scm, struct scm, struct scm);
struct scm for_each(struct scm, struct scm, struct scm);
struct scm for_each_between(struct scm, struct scm, struct scm, struct scm);
struct scm test(struct scm);
struct scm test_2(struct scm);
struct scm scm_main(struct scm);
struct scm g2506(struct scm, struct scm);
struct scm g2505(struct scm, struct scm);
struct scm g2504(struct scm, struct scm);
struct scm g2503(struct scm, struct scm);
struct scm g2502(struct scm, struct scm);
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

struct scm begin(struct scm env2498, struct scm a, struct scm b) {
    struct scm r16;
    r16 = b;
    return r16;
}

struct scm for_each(struct scm env2498, struct scm f, struct scm l) {
    struct scm r17;
    struct scm r18;
    struct scm r19;
    struct scm r20;
    struct scm r24;
    struct scm r28;
    struct scm r32;
    struct scm r33;
    struct scm r37;
    r18 = l;
    if (scm_extract_truth(r18)) {
        struct scm clor21;
        clor21 = scm_wrap_fptr(begin);
        struct scm clor25;
        clor25 = f;
        struct scm clor29;
        clor29 = scm_wrap_fptr(car);
        r28 = l;
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
        struct scm clor34;
        clor34 = scm_wrap_fptr(for_each);
        r32 = f;
        struct scm clor38;
        clor38 = scm_wrap_fptr(cdr);
        r37 = l;
        scm_fptr clo39;
        struct scm env40;
        clo39 = clor38.val.v->elt[0].val.f;
        env40 = clor38.val.v->elt[1];
        r33 = clo39(env40, r37);
        scm_fptr clo35;
        struct scm env36;
        clo35 = clor34.val.v->elt[0].val.f;
        env36 = clor34.val.v->elt[1];
        r20 = clo35(env36, r32, r33);
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

struct scm for_each_between(struct scm env2498, struct scm f, struct scm comma, struct scm list) {
    struct scm r41;
    struct scm r42;
    struct scm r43;
    struct scm r44;
    struct scm r48;
    struct scm r49;
    struct scm r53;
    struct scm r57;
    struct scm r61;
    struct scm r62;
    struct scm r66;
    struct scm r70;
    struct scm r71;
    struct scm r72;
    struct scm r76;
    struct scm r80;
    struct scm r84;
    r42 = list;
    if (scm_extract_truth(r42)) {
        struct scm clor45;
        clor45 = scm_wrap_fptr(cdr);
        r44 = list;
        scm_fptr clo46;
        struct scm env47;
        clo46 = clor45.val.v->elt[0].val.f;
        env47 = clor45.val.v->elt[1];
        r43 = clo46(env47, r44);
        if (scm_extract_truth(r43)) {
            struct scm clor50;
            clor50 = scm_wrap_fptr(begin);
            struct scm clor54;
            clor54 = f;
            struct scm clor58;
            clor58 = scm_wrap_fptr(car);
            r57 = list;
            scm_fptr clo59;
            struct scm env60;
            clo59 = clor58.val.v->elt[0].val.f;
            env60 = clor58.val.v->elt[1];
            r53 = clo59(env60, r57);
            scm_fptr clo55;
            struct scm env56;
            clo55 = clor54.val.v->elt[0].val.f;
            env56 = clor54.val.v->elt[1];
            r48 = clo55(env56, r53);
            struct scm clor63;
            clor63 = scm_wrap_fptr(begin);
            struct scm clor67;
            clor67 = comma;
            r66 = (struct scm){ .tag = 0, .val.i = 1 };
            scm_fptr clo68;
            struct scm env69;
            clo68 = clor67.val.v->elt[0].val.f;
            env69 = clor67.val.v->elt[1];
            r61 = clo68(env69, r66);
            struct scm clor73;
            clor73 = scm_wrap_fptr(for_each_between);
            r70 = f;
            r71 = comma;
            struct scm clor77;
            clor77 = scm_wrap_fptr(cdr);
            r76 = list;
            scm_fptr clo78;
            struct scm env79;
            clo78 = clor77.val.v->elt[0].val.f;
            env79 = clor77.val.v->elt[1];
            r72 = clo78(env79, r76);
            scm_fptr clo74;
            struct scm env75;
            clo74 = clor73.val.v->elt[0].val.f;
            env75 = clor73.val.v->elt[1];
            r62 = clo74(env75, r70, r71, r72);
            scm_fptr clo64;
            struct scm env65;
            clo64 = clor63.val.v->elt[0].val.f;
            env65 = clor63.val.v->elt[1];
            r49 = clo64(env65, r61, r62);
            scm_fptr clo51;
            struct scm env52;
            clo51 = clor50.val.v->elt[0].val.f;
            env52 = clor50.val.v->elt[1];
            r41 = clo51(env52, r48, r49);
        } else {
            struct scm clor81;
            clor81 = f;
            struct scm clor85;
            clor85 = scm_wrap_fptr(car);
            r84 = list;
            scm_fptr clo86;
            struct scm env87;
            clo86 = clor85.val.v->elt[0].val.f;
            env87 = clor85.val.v->elt[1];
            r80 = clo86(env87, r84);
            scm_fptr clo82;
            struct scm env83;
            clo82 = clor81.val.v->elt[0].val.f;
            env83 = clor81.val.v->elt[1];
            r41 = clo82(env83, r80);
        }
    } else {
        r41 = (struct scm){ .tag = 0, .val.i = 0 };
    }
    return r41;
}

struct scm test(struct scm env2498) {
    struct scm r88;
    struct scm r89;
    r89 = allocate_vector(0);
    r88 = make_closure(g2503, r89);
    return r88;
}

struct scm test_2(struct scm env2498) {
    struct scm r90;
    struct scm r91;
    r91 = allocate_vector(0);
    r90 = make_closure(g2506, r91);
    return r90;
}

struct scm scm_main(struct scm env2498) {
    struct scm r92;
    struct scm r93;
    struct scm r94;
    struct scm r98;
    struct scm r99;
    struct scm r106;
    struct scm r107;
    struct scm r111;
    struct scm r112;
    struct scm r116;
    struct scm r117;
    struct scm r121;
    struct scm r122;
    struct scm r129;
    struct scm r130;
    struct scm r134;
    struct scm r135;
    struct scm r139;
    struct scm r140;
    struct scm clor95;
    clor95 = scm_wrap_fptr(begin);
    struct scm clor100;
    clor100 = scm_wrap_fptr(for_each);
    struct scm clor103;
    clor103 = scm_wrap_fptr(test_2);
    scm_fptr clo104;
    struct scm env105;
    clo104 = clor103.val.v->elt[0].val.f;
    env105 = clor103.val.v->elt[1];
    r98 = clo104(env105);
    struct scm clor108;
    clor108 = scm_wrap_fptr(cons);
    r106 = (struct scm){ .tag = 0, .val.i = 67676767 };
    struct scm clor113;
    clor113 = scm_wrap_fptr(cons);
    r111 = (struct scm){ .tag = 0, .val.i = 252525 };
    struct scm clor118;
    clor118 = scm_wrap_fptr(cons);
    r116 = (struct scm){ .tag = 0, .val.i = 484848 };
    r117 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo119;
    struct scm env120;
    clo119 = clor118.val.v->elt[0].val.f;
    env120 = clor118.val.v->elt[1];
    r112 = clo119(env120, r116, r117);
    scm_fptr clo114;
    struct scm env115;
    clo114 = clor113.val.v->elt[0].val.f;
    env115 = clor113.val.v->elt[1];
    r107 = clo114(env115, r111, r112);
    scm_fptr clo109;
    struct scm env110;
    clo109 = clor108.val.v->elt[0].val.f;
    env110 = clor108.val.v->elt[1];
    r99 = clo109(env110, r106, r107);
    scm_fptr clo101;
    struct scm env102;
    clo101 = clor100.val.v->elt[0].val.f;
    env102 = clor100.val.v->elt[1];
    r93 = clo101(env102, r98, r99);
    struct scm clor123;
    clor123 = scm_wrap_fptr(for_each);
    struct scm clor126;
    clor126 = scm_wrap_fptr(test);
    scm_fptr clo127;
    struct scm env128;
    clo127 = clor126.val.v->elt[0].val.f;
    env128 = clor126.val.v->elt[1];
    r121 = clo127(env128);
    struct scm clor131;
    clor131 = scm_wrap_fptr(cons);
    r129 = (struct scm){ .tag = 0, .val.i = 67676767 };
    struct scm clor136;
    clor136 = scm_wrap_fptr(cons);
    r134 = (struct scm){ .tag = 0, .val.i = 252525 };
    struct scm clor141;
    clor141 = scm_wrap_fptr(cons);
    r139 = (struct scm){ .tag = 0, .val.i = 484848 };
    r140 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo142;
    struct scm env143;
    clo142 = clor141.val.v->elt[0].val.f;
    env143 = clor141.val.v->elt[1];
    r135 = clo142(env143, r139, r140);
    scm_fptr clo137;
    struct scm env138;
    clo137 = clor136.val.v->elt[0].val.f;
    env138 = clor136.val.v->elt[1];
    r130 = clo137(env138, r134, r135);
    scm_fptr clo132;
    struct scm env133;
    clo132 = clor131.val.v->elt[0].val.f;
    env133 = clor131.val.v->elt[1];
    r122 = clo132(env133, r129, r130);
    scm_fptr clo124;
    struct scm env125;
    clo124 = clor123.val.v->elt[0].val.f;
    env125 = clor123.val.v->elt[1];
    r94 = clo124(env125, r121, r122);
    scm_fptr clo96;
    struct scm env97;
    clo96 = clor95.val.v->elt[0].val.f;
    env97 = clor95.val.v->elt[1];
    r92 = clo96(env97, r93, r94);
    return r92;
}

struct scm g2506(struct scm env2498, struct scm i) {
    struct scm r144;
    struct scm r145;
    struct scm r146;
    struct scm r147;
    struct scm r151;
    struct scm r152;
    struct scm r153;
    struct scm r154;
    struct scm r158;
    struct scm r159;
    struct scm r163;
    struct scm r164;
    struct scm r168;
    struct scm r169;
    struct scm r173;
    struct scm r174;
    struct scm clor148;
    clor148 = scm_wrap_fptr(for_each_between);
    r151 = allocate_vector(0);
    r145 = make_closure(g2504, r151);
    r152 = allocate_vector(0);
    r146 = make_closure(g2505, r152);
    struct scm clor155;
    clor155 = scm_wrap_fptr(cons);
    r153 = i;
    struct scm clor160;
    clor160 = scm_wrap_fptr(cons);
    struct scm clor165;
    clor165 = scm_wrap_fptr(scm_plus);
    r163 = i;
    r164 = (struct scm){ .tag = 0, .val.i = 1 };
    scm_fptr clo166;
    struct scm env167;
    clo166 = clor165.val.v->elt[0].val.f;
    env167 = clor165.val.v->elt[1];
    r158 = clo166(env167, r163, r164);
    struct scm clor170;
    clor170 = scm_wrap_fptr(cons);
    struct scm clor175;
    clor175 = scm_wrap_fptr(scm_plus);
    r173 = i;
    r174 = (struct scm){ .tag = 0, .val.i = 2 };
    scm_fptr clo176;
    struct scm env177;
    clo176 = clor175.val.v->elt[0].val.f;
    env177 = clor175.val.v->elt[1];
    r168 = clo176(env177, r173, r174);
    r169 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo171;
    struct scm env172;
    clo171 = clor170.val.v->elt[0].val.f;
    env172 = clor170.val.v->elt[1];
    r159 = clo171(env172, r168, r169);
    scm_fptr clo161;
    struct scm env162;
    clo161 = clor160.val.v->elt[0].val.f;
    env162 = clor160.val.v->elt[1];
    r154 = clo161(env162, r158, r159);
    scm_fptr clo156;
    struct scm env157;
    clo156 = clor155.val.v->elt[0].val.f;
    env157 = clor155.val.v->elt[1];
    r147 = clo156(env157, r153, r154);
    scm_fptr clo149;
    struct scm env150;
    clo149 = clor148.val.v->elt[0].val.f;
    env150 = clor148.val.v->elt[1];
    r144 = clo149(env150, r145, r146, r147);
    return r144;
}

struct scm g2505(struct scm env2498, struct scm n) {
    struct scm r178;
    struct scm r179;
    struct scm clor180;
    clor180 = scm_wrap_fptr(scm_print);
    r179 = scm_string_to_vector("LUCKY! ");
    scm_fptr clo181;
    struct scm env182;
    clo181 = clor180.val.v->elt[0].val.f;
    env182 = clor180.val.v->elt[1];
    r178 = clo181(env182, r179);
    return r178;
}

struct scm g2504(struct scm env2498, struct scm i) {
    struct scm r183;
    struct scm r184;
    struct scm r185;
    struct scm r189;
    struct scm r193;
    struct scm clor186;
    clor186 = scm_wrap_fptr(begin);
    struct scm clor190;
    clor190 = scm_wrap_fptr(scm_print);
    r189 = scm_string_to_vector("HAPPY! ");
    scm_fptr clo191;
    struct scm env192;
    clo191 = clor190.val.v->elt[0].val.f;
    env192 = clor190.val.v->elt[1];
    r184 = clo191(env192, r189);
    struct scm clor194;
    clor194 = scm_wrap_fptr(scm_print);
    r193 = i;
    scm_fptr clo195;
    struct scm env196;
    clo195 = clor194.val.v->elt[0].val.f;
    env196 = clor194.val.v->elt[1];
    r185 = clo195(env196, r193);
    scm_fptr clo187;
    struct scm env188;
    clo187 = clor186.val.v->elt[0].val.f;
    env188 = clor186.val.v->elt[1];
    r183 = clo187(env188, r184, r185);
    return r183;
}

struct scm g2503(struct scm env2498, struct scm i) {
    struct scm r197;
    struct scm r198;
    struct scm r199;
    struct scm r203;
    struct scm r204;
    struct scm r205;
    struct scm r209;
    struct scm r210;
    struct scm r214;
    struct scm r215;
    struct scm r219;
    struct scm r220;
    struct scm r224;
    struct scm r225;
    struct scm clor200;
    clor200 = scm_wrap_fptr(for_each);
    r203 = allocate_vector(0);
    r198 = make_closure(g2502, r203);
    struct scm clor206;
    clor206 = scm_wrap_fptr(cons);
    r204 = i;
    struct scm clor211;
    clor211 = scm_wrap_fptr(cons);
    struct scm clor216;
    clor216 = scm_wrap_fptr(scm_plus);
    r214 = i;
    r215 = (struct scm){ .tag = 0, .val.i = 1 };
    scm_fptr clo217;
    struct scm env218;
    clo217 = clor216.val.v->elt[0].val.f;
    env218 = clor216.val.v->elt[1];
    r209 = clo217(env218, r214, r215);
    struct scm clor221;
    clor221 = scm_wrap_fptr(cons);
    struct scm clor226;
    clor226 = scm_wrap_fptr(scm_plus);
    r224 = i;
    r225 = (struct scm){ .tag = 0, .val.i = 2 };
    scm_fptr clo227;
    struct scm env228;
    clo227 = clor226.val.v->elt[0].val.f;
    env228 = clor226.val.v->elt[1];
    r219 = clo227(env228, r224, r225);
    r220 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo222;
    struct scm env223;
    clo222 = clor221.val.v->elt[0].val.f;
    env223 = clor221.val.v->elt[1];
    r210 = clo222(env223, r219, r220);
    scm_fptr clo212;
    struct scm env213;
    clo212 = clor211.val.v->elt[0].val.f;
    env213 = clor211.val.v->elt[1];
    r205 = clo212(env213, r209, r210);
    scm_fptr clo207;
    struct scm env208;
    clo207 = clor206.val.v->elt[0].val.f;
    env208 = clor206.val.v->elt[1];
    r199 = clo207(env208, r204, r205);
    scm_fptr clo201;
    struct scm env202;
    clo201 = clor200.val.v->elt[0].val.f;
    env202 = clor200.val.v->elt[1];
    r197 = clo201(env202, r198, r199);
    return r197;
}

struct scm g2502(struct scm env2498, struct scm i) {
    struct scm r229;
    struct scm r230;
    struct scm r231;
    struct scm r235;
    struct scm r239;
    struct scm clor232;
    clor232 = scm_wrap_fptr(begin);
    struct scm clor236;
    clor236 = scm_wrap_fptr(scm_print);
    r235 = scm_string_to_vector("DOCHY! ");
    scm_fptr clo237;
    struct scm env238;
    clo237 = clor236.val.v->elt[0].val.f;
    env238 = clor236.val.v->elt[1];
    r230 = clo237(env238, r235);
    struct scm clor240;
    clor240 = scm_wrap_fptr(scm_print);
    r239 = i;
    scm_fptr clo241;
    struct scm env242;
    clo241 = clor240.val.v->elt[0].val.f;
    env242 = clor240.val.v->elt[1];
    r231 = clo241(env242, r239);
    scm_fptr clo233;
    struct scm env234;
    clo233 = clor232.val.v->elt[0].val.f;
    env234 = clor232.val.v->elt[1];
    r229 = clo233(env234, r230, r231);
    return r229;
}

struct scm g2501(struct scm env2498, struct scm x, struct scm y) {
    struct scm r243;
    r243 = y;
    return r243;
}

struct scm g2500(struct scm env2498, struct scm x, struct scm y) {
    struct scm r244;
    r244 = x;
    return r244;
}

struct scm g2499(struct scm env2498, struct scm selector) {
    struct scm r245;
    struct scm r246;
    struct scm r247;
    struct scm r251;
    struct scm r252;
    struct scm r253;
    struct scm r254;
    struct scm clor248;
    clor248 = selector;
    r251 = env2498;
    r252 = (struct scm){ .tag = 0, .val.i = 1 };
    r246 = scm_vector_ref(r251, r252);
    r253 = env2498;
    r254 = (struct scm){ .tag = 0, .val.i = 0 };
    r247 = scm_vector_ref(r253, r254);
    scm_fptr clo249;
    struct scm env250;
    clo249 = clor248.val.v->elt[0].val.f;
    env250 = clor248.val.v->elt[1];
    r245 = clo249(env250, r246, r247);
    return r245;
}

