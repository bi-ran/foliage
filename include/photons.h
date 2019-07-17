#ifndef PHOTONS_H
#define PHOTONS_H

#include "foliage.h"

#include "TTree.h"

#include <vector>

#define B_VAL_PHO_RECO(ACTION, ...)                                         \
    ACTION(uint32_t,        run,                        ## __VA_ARGS__)     \
    ACTION(uint32_t,        lumis,                      ## __VA_ARGS__)     \
                                                                            \
    ACTION(int32_t,         nPho,                       ## __VA_ARGS__)     \

#define B_VEC_PHO_RECO(ACTION, ...)                                         \
    ACTION(sv<float>,       phoE,                       ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoEt,                      ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoEta,                     ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoPhi,                     ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<float>,       phoSCE,                     ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoSCEta,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoSCPhi,                   ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<float>,       phoHoverE,                  ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoR9_2012,                 ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoSigmaIEtaIEta_2012,      ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<float>,       pho_ecalClusterIsoR4,       ## __VA_ARGS__)     \
    ACTION(sv<float>,       pho_hcalRechitIsoR4,        ## __VA_ARGS__)     \
    ACTION(sv<float>,       pho_trackIsoR4PtCut20,      ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<float>,       pho_swissCrx,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       pho_seedTime,               ## __VA_ARGS__)     \

class photons {
  public:
    photons(TTree* t);

    photons(photons const&) = delete;
    photons& operator=(photons const&) = delete;
    ~photons() = default;

    B_VAL_PHO_RECO(DECLVAL)
    B_VEC_PHO_RECO(DECLPTR)

  private:
    void read(TTree* t);
};

#endif  /* PHOTONS_H */
