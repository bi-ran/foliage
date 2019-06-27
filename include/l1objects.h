#ifndef L1OBJECTS_H
#define L1OBJECTS_H

#include "foliage.h"

#include "TTree.h"

#define B_ALL_L1O(ACTION, ...)                                              \
    B_VAL_L1O(ACTION,                                   ## __VA_ARGS__)     \
    B_VEC_L1O(ACTION,                                   ## __VA_ARGS__)     \

#define B_VAL_L1O(ACTION, ...)                                              \
    ACTION(int,             nEGs,                       ## __VA_ARGS__)     \

#define B_VEC_L1O(ACTION, ...)                                              \
    ACTION(sv<float>,       egEt,                       ## __VA_ARGS__)     \
    ACTION(sv<float>,       egEta,                      ## __VA_ARGS__)     \
    ACTION(sv<float>,       egPhi,                      ## __VA_ARGS__)     \

class l1objects {
  public:
    l1objects(TTree* t);

    l1objects(l1objects const&) = delete;
    l1objects& operator=(l1objects const&) = delete;
    ~l1objects() = default;

    void read(TTree* t);

    B_VAL_L1O(DECLVAL)
    B_VEC_L1O(DECLPTR)
};

#endif  /* L1OBJECTS_H */
