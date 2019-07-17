#ifndef EGGEN_H
#define EGGEN_H

#include "foliage.h"

#include "TTree.h"

#include <vector>

#define B_VAL_EGM_GEN(ACTION, ...)                                          \
    ACTION(int32_t,         nMC,                        ## __VA_ARGS__)     \

#define B_VEC_EGM_GEN(ACTION, ...)                                          \
    ACTION(sv<float>,       mcVtx_x,                    ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcVtx_y,                    ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcVtx_z,                    ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<int>,         mcPID,                      ## __VA_ARGS__)     \
    ACTION(sv<int>,         mcStatus,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcPt,                       ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcEta,                      ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcPhi,                      ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcE,                        ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcEt,                       ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcMass,                     ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<int>,         mcMomPID,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcMomPt,                    ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcMomEta,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcMomPhi,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcMomMass,                  ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<float>,       mcCalIsoDR04,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcTrkIsoDR04,               ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<int>,         pho_genMatchedIndex,        ## __VA_ARGS__)     \

class eggen {
  public:
    eggen(TTree* t, bool gen);

    eggen(eggen const&) = delete;
    eggen& operator=(eggen const&) = delete;
    ~eggen() = default;

    B_VAL_EGM_GEN(DECLVAL)
    B_VEC_EGM_GEN(DECLPTR)

  private:
    bool _gen;

    void read(TTree* t);
};

#endif  /* EGGEN_H */
