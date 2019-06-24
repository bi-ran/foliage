#ifndef JETS_H
#define JETS_H

#include "foliage.h"

#include "TTree.h"

#define B_ALL_JET_RECO(ACTION, ...)                                         \
    B_VAL_JET_RECO(ACTION,                              ## __VA_ARGS__)     \
    B_ARR_JET_RECO(ACTION,                              ## __VA_ARGS__)     \

#define B_VAL_JET_RECO(ACTION, ...)                                         \
    ACTION(int,             nref,                       ## __VA_ARGS__)     \

#define B_ARR_JET_RECO(ACTION, ...)                                         \
    ACTION(float,           rawpt,                      ## __VA_ARGS__)     \
    ACTION(float,           jtpt,                       ## __VA_ARGS__)     \
    ACTION(float,           jteta,                      ## __VA_ARGS__)     \
    ACTION(float,           jtphi,                      ## __VA_ARGS__)     \

#define B_ALL_JET_GEN(ACTION, ...)                                          \
    B_VAL_JET_GEN(ACTION,                               ## __VA_ARGS__)     \
    B_ARR_JET_GEN(ACTION,                               ## __VA_ARGS__)     \

#define B_VAL_JET_GEN(ACTION, ...)                                          \
    ACTION(int,             ngen,                       ## __VA_ARGS__)     \

#define B_ARR_JET_GEN(ACTION, ...)                                          \
    ACTION(float,           genpt,                      ## __VA_ARGS__)     \
    ACTION(float,           geneta,                     ## __VA_ARGS__)     \
    ACTION(float,           genphi,                     ## __VA_ARGS__)     \

class jets {
  public:
    jets(TTree* t, bool gen, int64_t size);

    jets(jets const&) = delete;
    jets& operator=(jets const&) = delete;
    ~jets() = default;

    void read(TTree* t);

    B_VAL_JET_RECO(DECLVAL)
    B_VAL_JET_GEN(DECLVAL)
    B_ARR_JET_RECO(DECLPTR)
    B_ARR_JET_GEN(DECLPTR)

  private:
    bool _gen;
};

#endif  /* JETS_H */
