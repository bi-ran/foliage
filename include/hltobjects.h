#ifndef HLTOBJECTS_H
#define HLTOBJECTS_H

#include "foliage.h"

#include "TTree.h"

#define B_ALL_HLT(ACTION, ...)                                              \
    B_VEC_HLT(ACTION,                                   ## __VA_ARGS__)     \

#define B_VEC_HLT(ACTION, ...)                                              \
    ACTION(sv<double>,      pt,                         ## __VA_ARGS__)     \
    ACTION(sv<double>,      eta,                        ## __VA_ARGS__)     \
    ACTION(sv<double>,      phi,                        ## __VA_ARGS__)     \
    ACTION(sv<double>,      mass,                       ## __VA_ARGS__)     \

class hltobjects {
  public:
    hltobjects(TTree* t);

    hltobjects(hltobjects const&) = delete;
    hltobjects& operator=(hltobjects const&) = delete;
    ~hltobjects() = default;

    void read(TTree* t);

    B_VEC_HLT(DECLPTR)
};

#endif  /* HLTOBJECTS_H */
