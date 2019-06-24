#include "../include/photons.h"

photons::photons(TTree* t, bool gen)
        : _gen(gen) {
    B_VAL_PHO_RECO(SETZERO)
    B_VEC_PHO_RECO(SETZERO)

    if (_gen) {
        B_VAL_PHO_GEN(SETZERO)
        B_VEC_PHO_GEN(SETZERO)
    }

    read(t);
}

void photons::read(TTree* t) {
    B_VAL_PHO_RECO(SETVALADDR, t)
    B_VEC_PHO_RECO(SETVALADDR, t)

    if (_gen) {
        B_VAL_PHO_GEN(SETVALADDR, t)
        B_VEC_PHO_GEN(SETVALADDR, t)
    }
}
