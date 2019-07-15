#include "../include/event.h"

event::event(TTree* t, bool gen)
        : _gen(gen) {
    B_VAL_EVT_RECO(SETZERO)

    if (_gen) {
        B_VAL_EVT_GEN(SETZERO)
    }

    read(t);
}

void event::read(TTree* t) {
    B_VAL_EVT_RECO(SETVALADDR, t)

    if (_gen) {
        B_VAL_EVT_GEN(SETVALADDR, t)
    }
}
