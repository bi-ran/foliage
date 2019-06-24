#include "../include/tracks.h"

tracks::tracks(TTree* t, int64_t size) {
    B_VAL_TRK_RECO(SETZERO)
    B_ARR_TRK_RECO(ALLOCARR, size)

    read(t);
}

void tracks::read(TTree* t) {
    B_VAL_TRK_RECO(SETVALADDR, t)
    B_ARR_TRK_RECO(SETPTRADDR, t)
}
