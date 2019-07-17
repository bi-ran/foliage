#include "../include/electrons.h"

electrons::electrons(TTree* t) {
    B_VAL_ELE_RECO(SETZERO)
    B_VEC_ELE_RECO(SETZERO)

    read(t);
}

void electrons::read(TTree* t) {
    B_VAL_ELE_RECO(SETVALADDR, t)
    B_VEC_ELE_RECO(SETVALADDR, t)
}
