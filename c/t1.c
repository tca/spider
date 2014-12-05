#include "runtime.c"
struct scm scm_main(struct scm);

struct scm scm_main(struct scm env2498) {
    struct scm r0;
    struct scm r1;
    struct scm clor2;
    clor2 = scm_wrap_fptr(scm_print);
    r1 = scm_string_to_vector("Hello world");
    scm_fptr clo3;
    struct scm env4;
    clo3 = clor2.val.v->elt[0].val.f;
    env4 = clor2.val.v->elt[1];
    r0 = clo3(env4, r1);
    return r0;
}

