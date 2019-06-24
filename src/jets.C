#include "../include/jets.h"

jets::jets(TTree* t, bool gen, int64_t size)
        : _gen(gen) {
    B_VAL_JET_RECO(SETZERO)
    B_ARR_JET_RECO(ALLOCARR, size)

    if (_gen) {
        B_VAL_JET_GEN(SETZERO)
        B_ARR_JET_GEN(ALLOCARR, size)
    }

    read(t);
}

void jets::read(TTree* t) {
    B_VAL_JET_RECO(SETVALADDR, t)
    B_ARR_JET_RECO(SETPTRADDR, t)

    if (_gen) {
        B_VAL_JET_GEN(SETVALADDR, t)
        B_ARR_JET_GEN(SETPTRADDR, t)
    }
}
