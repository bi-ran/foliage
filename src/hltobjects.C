#include "../include/hltobjects.h"

hltobjects::hltobjects(TTree* t) {
    B_VEC_HLT(SETZERO)

    read(t);
}

void hltobjects::read(TTree* t) {
    B_VEC_HLT(SETVALADDR, t)
}
