#include "../include/photons.h"

photons::photons(TTree* t) {
    B_VAL_PHO_RECO(SETZERO)
    B_VEC_PHO_RECO(SETZERO)

    read(t);
}

void photons::read(TTree* t) {
    B_VAL_PHO_RECO(SETVALADDR, t)
    B_VEC_PHO_RECO(SETVALADDR, t)
}
