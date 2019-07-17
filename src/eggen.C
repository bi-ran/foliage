#include "../include/eggen.h"

eggen::eggen(TTree* t, bool gen)
        : _gen(gen) {
    B_VAL_EGM_GEN(SETZERO)
    B_VEC_EGM_GEN(SETZERO)

    read(t);
}

void eggen::read(TTree* t) {
    if (_gen) {
        B_VAL_EGM_GEN(SETVALADDR, t)
        B_VEC_EGM_GEN(SETVALADDR, t)
    }
}
