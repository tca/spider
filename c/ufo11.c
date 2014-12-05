#include "runtime.c"
struct scm cons(struct scm, struct scm, struct scm);
struct scm car(struct scm, struct scm);
struct scm cdr(struct scm, struct scm);
struct scm begin(struct scm, struct scm, struct scm);
struct scm for_each(struct scm, struct scm, struct scm);
struct scm map(struct scm, struct scm, struct scm);
struct scm append(struct scm, struct scm, struct scm);
struct scm loop(struct scm, struct scm, struct scm, struct scm);
struct scm sierpinski(struct scm, struct scm);
struct scm scm_main(struct scm);
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

struct scm map(struct scm env2498, struct scm f, struct scm l) {
    struct scm r41;
    struct scm r42;
    struct scm r43;
    struct scm r44;
    struct scm r48;
    struct scm r52;
    struct scm r56;
    struct scm r57;
    struct scm r61;
    r42 = l;
    if (scm_extract_truth(r42)) {
        struct scm clor45;
        clor45 = scm_wrap_fptr(cons);
        struct scm clor49;
        clor49 = f;
        struct scm clor53;
        clor53 = scm_wrap_fptr(car);
        r52 = l;
        scm_fptr clo54;
        struct scm env55;
        clo54 = clor53.val.v->elt[0].val.f;
        env55 = clor53.val.v->elt[1];
        r48 = clo54(env55, r52);
        scm_fptr clo50;
        struct scm env51;
        clo50 = clor49.val.v->elt[0].val.f;
        env51 = clor49.val.v->elt[1];
        r43 = clo50(env51, r48);
        struct scm clor58;
        clor58 = scm_wrap_fptr(map);
        r56 = f;
        struct scm clor62;
        clor62 = scm_wrap_fptr(cdr);
        r61 = l;
        scm_fptr clo63;
        struct scm env64;
        clo63 = clor62.val.v->elt[0].val.f;
        env64 = clor62.val.v->elt[1];
        r57 = clo63(env64, r61);
        scm_fptr clo59;
        struct scm env60;
        clo59 = clor58.val.v->elt[0].val.f;
        env60 = clor58.val.v->elt[1];
        r44 = clo59(env60, r56, r57);
        scm_fptr clo46;
        struct scm env47;
        clo46 = clor45.val.v->elt[0].val.f;
        env47 = clor45.val.v->elt[1];
        r41 = clo46(env47, r43, r44);
    } else {
        r41 = (struct scm){ .tag = 0, .val.i = 0 };
    }
    return r41;
}

struct scm append(struct scm env2498, struct scm a, struct scm b) {
    struct scm r65;
    struct scm r66;
    struct scm r67;
    struct scm r68;
    struct scm r72;
    struct scm r76;
    struct scm r77;
    struct scm r81;
    r66 = a;
    if (scm_extract_truth(r66)) {
        struct scm clor69;
        clor69 = scm_wrap_fptr(cons);
        struct scm clor73;
        clor73 = scm_wrap_fptr(car);
        r72 = a;
        scm_fptr clo74;
        struct scm env75;
        clo74 = clor73.val.v->elt[0].val.f;
        env75 = clor73.val.v->elt[1];
        r67 = clo74(env75, r72);
        struct scm clor78;
        clor78 = scm_wrap_fptr(append);
        struct scm clor82;
        clor82 = scm_wrap_fptr(cdr);
        r81 = a;
        scm_fptr clo83;
        struct scm env84;
        clo83 = clor82.val.v->elt[0].val.f;
        env84 = clor82.val.v->elt[1];
        r76 = clo83(env84, r81);
        r77 = b;
        scm_fptr clo79;
        struct scm env80;
        clo79 = clor78.val.v->elt[0].val.f;
        env80 = clor78.val.v->elt[1];
        r68 = clo79(env80, r76, r77);
        scm_fptr clo70;
        struct scm env71;
        clo70 = clor69.val.v->elt[0].val.f;
        env71 = clor69.val.v->elt[1];
        r65 = clo70(env71, r67, r68);
    } else {
        r65 = b;
    }
    return r65;
}

struct scm loop(struct scm env2498, struct scm acc, struct scm spaces, struct scm n) {
    struct scm r85;
    struct scm r86;
    struct scm r87;
    struct scm r88;
    struct scm r89;
    struct scm r93;
    struct scm r94;
    struct scm r98;
    struct scm r99;
    struct scm r103;
    struct scm r104;
    struct scm r105;
    struct scm r106;
    struct scm r110;
    struct scm r111;
    struct scm r112;
    struct scm r116;
    struct scm r117;
    r86 = n;
    if (scm_extract_truth(r86)) {
        struct scm clor90;
        clor90 = scm_wrap_fptr(loop);
        struct scm clor95;
        clor95 = scm_wrap_fptr(append);
        struct scm clor100;
        clor100 = scm_wrap_fptr(map);
        r104 = spaces;
        r103 = allocate_vector(1);
        scm_vector_insert_bang(r103, r104, 0);
        r98 = make_closure(g2502, r103);
        r99 = acc;
        scm_fptr clo101;
        struct scm env102;
        clo101 = clor100.val.v->elt[0].val.f;
        env102 = clor100.val.v->elt[1];
        r93 = clo101(env102, r98, r99);
        struct scm clor107;
        clor107 = scm_wrap_fptr(map);
        r110 = allocate_vector(0);
        r105 = make_closure(g2503, r110);
        r106 = acc;
        scm_fptr clo108;
        struct scm env109;
        clo108 = clor107.val.v->elt[0].val.f;
        env109 = clor107.val.v->elt[1];
        r94 = clo108(env109, r105, r106);
        scm_fptr clo96;
        struct scm env97;
        clo96 = clor95.val.v->elt[0].val.f;
        env97 = clor95.val.v->elt[1];
        r87 = clo96(env97, r93, r94);
        struct scm clor113;
        clor113 = scm_wrap_fptr(append);
        r111 = spaces;
        r112 = spaces;
        scm_fptr clo114;
        struct scm env115;
        clo114 = clor113.val.v->elt[0].val.f;
        env115 = clor113.val.v->elt[1];
        r88 = clo114(env115, r111, r112);
        struct scm clor118;
        clor118 = scm_wrap_fptr(scm_minus);
        r116 = n;
        r117 = (struct scm){ .tag = 0, .val.i = 1 };
        scm_fptr clo119;
        struct scm env120;
        clo119 = clor118.val.v->elt[0].val.f;
        env120 = clor118.val.v->elt[1];
        r89 = clo119(env120, r116, r117);
        scm_fptr clo91;
        struct scm env92;
        clo91 = clor90.val.v->elt[0].val.f;
        env92 = clor90.val.v->elt[1];
        r85 = clo91(env92, r87, r88, r89);
    } else {
        r85 = acc;
    }
    return r85;
}

struct scm sierpinski(struct scm env2498, struct scm n) {
    struct scm r121;
    struct scm r122;
    struct scm r123;
    struct scm r127;
    struct scm r128;
    struct scm r129;
    struct scm r130;
    struct scm r134;
    struct scm r135;
    struct scm r139;
    struct scm r140;
    struct scm r144;
    struct scm r145;
    struct scm clor124;
    clor124 = scm_wrap_fptr(for_each);
    r127 = allocate_vector(0);
    r122 = make_closure(g2504, r127);
    struct scm clor131;
    clor131 = scm_wrap_fptr(loop);
    struct scm clor136;
    clor136 = scm_wrap_fptr(cons);
    struct scm clor141;
    clor141 = scm_wrap_fptr(cons);
    r139 = scm_string_to_vector("*");
    r140 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo142;
    struct scm env143;
    clo142 = clor141.val.v->elt[0].val.f;
    env143 = clor141.val.v->elt[1];
    r134 = clo142(env143, r139, r140);
    r135 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo137;
    struct scm env138;
    clo137 = clor136.val.v->elt[0].val.f;
    env138 = clor136.val.v->elt[1];
    r128 = clo137(env138, r134, r135);
    struct scm clor146;
    clor146 = scm_wrap_fptr(cons);
    r144 = scm_string_to_vector(" ");
    r145 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo147;
    struct scm env148;
    clo147 = clor146.val.v->elt[0].val.f;
    env148 = clor146.val.v->elt[1];
    r129 = clo147(env148, r144, r145);
    r130 = n;
    scm_fptr clo132;
    struct scm env133;
    clo132 = clor131.val.v->elt[0].val.f;
    env133 = clor131.val.v->elt[1];
    r123 = clo132(env133, r128, r129, r130);
    scm_fptr clo125;
    struct scm env126;
    clo125 = clor124.val.v->elt[0].val.f;
    env126 = clor124.val.v->elt[1];
    r121 = clo125(env126, r122, r123);
    return r121;
}

struct scm scm_main(struct scm env2498) {
    struct scm r149;
    struct scm r150;
    struct scm clor151;
    clor151 = scm_wrap_fptr(sierpinski);
    r150 = (struct scm){ .tag = 0, .val.i = 4 };
    scm_fptr clo152;
    struct scm env153;
    clo152 = clor151.val.v->elt[0].val.f;
    env153 = clor151.val.v->elt[1];
    r149 = clo152(env153, r150);
    return r149;
}

struct scm g2504(struct scm env2498, struct scm x) {
    struct scm r154;
    struct scm r155;
    struct scm r156;
    struct scm r160;
    struct scm r161;
    struct scm r165;
    struct scm clor157;
    clor157 = scm_wrap_fptr(begin);
    struct scm clor162;
    clor162 = scm_wrap_fptr(for_each);
    r160 = scm_wrap_fptr(scm_print);
    r161 = x;
    scm_fptr clo163;
    struct scm env164;
    clo163 = clor162.val.v->elt[0].val.f;
    env164 = clor162.val.v->elt[1];
    r155 = clo163(env164, r160, r161);
    struct scm clor166;
    clor166 = scm_wrap_fptr(scm_print);
    r165 = scm_string_to_vector("\n");
    scm_fptr clo167;
    struct scm env168;
    clo167 = clor166.val.v->elt[0].val.f;
    env168 = clor166.val.v->elt[1];
    r156 = clo167(env168, r165);
    scm_fptr clo158;
    struct scm env159;
    clo158 = clor157.val.v->elt[0].val.f;
    env159 = clor157.val.v->elt[1];
    r154 = clo158(env159, r155, r156);
    return r154;
}

struct scm g2503(struct scm env2498, struct scm x) {
    struct scm r169;
    struct scm r170;
    struct scm r171;
    struct scm r175;
    struct scm r176;
    struct scm r180;
    struct scm r181;
    struct scm clor172;
    clor172 = scm_wrap_fptr(append);
    r170 = x;
    struct scm clor177;
    clor177 = scm_wrap_fptr(append);
    struct scm clor182;
    clor182 = scm_wrap_fptr(cons);
    r180 = scm_string_to_vector(" ");
    r181 = (struct scm){ .tag = 0, .val.i = 0 };
    scm_fptr clo183;
    struct scm env184;
    clo183 = clor182.val.v->elt[0].val.f;
    env184 = clor182.val.v->elt[1];
    r175 = clo183(env184, r180, r181);
    r176 = x;
    scm_fptr clo178;
    struct scm env179;
    clo178 = clor177.val.v->elt[0].val.f;
    env179 = clor177.val.v->elt[1];
    r171 = clo178(env179, r175, r176);
    scm_fptr clo173;
    struct scm env174;
    clo173 = clor172.val.v->elt[0].val.f;
    env174 = clor172.val.v->elt[1];
    r169 = clo173(env174, r170, r171);
    return r169;
}

struct scm g2502(struct scm env2498, struct scm x) {
    struct scm r185;
    struct scm r186;
    struct scm r187;
    struct scm r191;
    struct scm r192;
    struct scm r193;
    struct scm r194;
    struct scm r198;
    struct scm r199;
    struct scm clor188;
    clor188 = scm_wrap_fptr(append);
    r191 = env2498;
    r192 = (struct scm){ .tag = 0, .val.i = 0 };
    r186 = scm_vector_ref(r191, r192);
    struct scm clor195;
    clor195 = scm_wrap_fptr(append);
    r193 = x;
    r198 = env2498;
    r199 = (struct scm){ .tag = 0, .val.i = 0 };
    r194 = scm_vector_ref(r198, r199);
    scm_fptr clo196;
    struct scm env197;
    clo196 = clor195.val.v->elt[0].val.f;
    env197 = clor195.val.v->elt[1];
    r187 = clo196(env197, r193, r194);
    scm_fptr clo189;
    struct scm env190;
    clo189 = clor188.val.v->elt[0].val.f;
    env190 = clor188.val.v->elt[1];
    r185 = clo189(env190, r186, r187);
    return r185;
}

struct scm g2501(struct scm env2498, struct scm x, struct scm y) {
    struct scm r200;
    r200 = y;
    return r200;
}

struct scm g2500(struct scm env2498, struct scm x, struct scm y) {
    struct scm r201;
    r201 = x;
    return r201;
}

struct scm g2499(struct scm env2498, struct scm selector) {
    struct scm r202;
    struct scm r203;
    struct scm r204;
    struct scm r208;
    struct scm r209;
    struct scm r210;
    struct scm r211;
    struct scm clor205;
    clor205 = selector;
    r208 = env2498;
    r209 = (struct scm){ .tag = 0, .val.i = 1 };
    r203 = scm_vector_ref(r208, r209);
    r210 = env2498;
    r211 = (struct scm){ .tag = 0, .val.i = 0 };
    r204 = scm_vector_ref(r210, r211);
    scm_fptr clo206;
    struct scm env207;
    clo206 = clor205.val.v->elt[0].val.f;
    env207 = clor205.val.v->elt[1];
    r202 = clo206(env207, r203, r204);
    return r202;
}

