#include "../include/electrons.h"

electrons::electrons(TTree* t, bool gen)
        : _gen(gen) {
    B_VAL_ELE_RECO(SETZERO)
    B_VEC_ELE_RECO(SETZERO)

    if (_gen) {
        B_VAL_ELE_GEN(SETZERO)
        B_VEC_ELE_GEN(SETZERO)
    }

    read(t);
}

void electrons::read(TTree* t) {
    B_VAL_ELE_RECO(SETVALADDR, t)
    B_VEC_ELE_RECO(SETVALADDR, t)

    if (_gen) {
        B_VAL_ELE_GEN(SETVALADDR, t)
        B_VEC_ELE_GEN(SETVALADDR, t)
    }
}
