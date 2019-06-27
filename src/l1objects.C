#include "../include/l1objects.h"

l1objects::l1objects(TTree* t) {
    B_VAL_L1O(SETZERO)
    B_VEC_L1O(SETZERO)

    read(t);
}

void l1objects::read(TTree* t) {
    B_VAL_L1O(SETVALADDR, t)
    B_VEC_L1O(SETVALADDR, t)
}
