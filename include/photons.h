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
    ACTION(sv<float>,       phoSCRawE,                  ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoSCEta,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoSCPhi,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoSCEtaWidth,              ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoSCPhiWidth,              ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoSCBrem,                  ## __VA_ARGS__)     \
    ACTION(sv<int>,         phoSCnHits,                 ## __VA_ARGS__)     \
    ACTION(sv<uint32_t>,    phoSCflags,                 ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoESEn,                    ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<float>,       phoHoverE,                  ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoR9_2012,                 ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoSigmaEtaEta_2012,        ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoSigmaIEtaIEta_2012,      ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoE1x5_2012,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoE2x5_2012,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoE3x3_2012,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoE5x5_2012,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoR1x5_2012,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       phoR2x5_2012,               ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<float>,       pho_ecalClusterIsoR3,       ## __VA_ARGS__)     \
    ACTION(sv<float>,       pho_ecalClusterIsoR4,       ## __VA_ARGS__)     \
    ACTION(sv<float>,       pho_hcalRechitIsoR3,        ## __VA_ARGS__)     \
    ACTION(sv<float>,       pho_hcalRechitIsoR4,        ## __VA_ARGS__)     \
    ACTION(sv<float>,       pho_trackIsoR3PtCut20,      ## __VA_ARGS__)     \
    ACTION(sv<float>,       pho_trackIsoR4PtCut20,      ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<float>,       pho_swissCrx,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       pho_seedTime,               ## __VA_ARGS__)     \

#define B_VAL_PHO_GEN(ACTION, ...)                                          \
    ACTION(int32_t,         nMC,                        ## __VA_ARGS__)     \

#define B_VEC_PHO_GEN(ACTION, ...)                                          \
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
    ACTION(sv<int>,         mcParentage,                ## __VA_ARGS__)     \
    ACTION(sv<int>,         mcMomPID,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcMomPt,                    ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcMomEta,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcMomPhi,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcMomMass,                  ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<float>,       mcCalIsoDR03,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcCalIsoDR04,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcTrkIsoDR03,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       mcTrkIsoDR04,               ## __VA_ARGS__)     \

class photons {
  public:
    photons(TTree* t, bool gen);

    photons(photons const&) = delete;
    photons& operator=(photons const&) = delete;
    ~photons() = default;

    void read(TTree* t);

    B_VAL_PHO_RECO(DECLVAL)
    B_VAL_PHO_GEN(DECLVAL)
    B_VEC_PHO_RECO(DECLPTR)
    B_VEC_PHO_GEN(DECLPTR)

  private:
    bool _gen;
};

#endif  /* PHOTONS_H */
