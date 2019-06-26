#ifndef ELECTRONS_H
#define ELECTRONS_H

#include "foliage.h"

#include "TTree.h"

#include <vector>

#define B_VAL_ELE_RECO(ACTION, ...)                                         \
    ACTION(uint32_t,        run,                        ## __VA_ARGS__)     \
    ACTION(uint32_t,        lumis,                      ## __VA_ARGS__)     \
                                                                            \
    ACTION(float,           rho,                        ## __VA_ARGS__)     \
                                                                            \
    ACTION(int32_t,         nEle,                       ## __VA_ARGS__)     \

#define B_VEC_ELE_RECO(ACTION, ...)                                         \
    ACTION(sv<float>,       elePt,                      ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleEta,                     ## __VA_ARGS__)     \
    ACTION(sv<float>,       elePhi,                     ## __VA_ARGS__)     \
    ACTION(sv<int>,         eleCharge,                  ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleD0,                      ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleDz,                      ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleD0Err,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleDzErr,                   ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<float>,       eleSCEn,                    ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleESEn,                    ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSCEta,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSCPhi,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSCRawEn,                 ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSCEtaWidth,              ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSCPhiWidth,              ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleHoverE,                  ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleHoverEBc,                ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleEoverP,                  ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleEoverPInv,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSigmaIEtaIEta_2012,      ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleESEffSigmaRR,            ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<float>,       eleTrkPt,                   ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleTrkEta,                  ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleTrkPhi,                  ## __VA_ARGS__)     \
    ACTION(sv<int>,         eleTrkCharge,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleTrkPtErr,                ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleTrkChi2,                 ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleTrkNdof,                 ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleTrkNormalizedChi2,       ## __VA_ARGS__)     \
    ACTION(sv<int>,         eleTrkValidHits,            ## __VA_ARGS__)     \
    ACTION(sv<int>,         eleTrkLayers,               ## __VA_ARGS__)     \
    ACTION(sv<int>,         eleMissHits,                ## __VA_ARGS__)     \
    ACTION(sv<float>,       eledEtaAtVtx,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       eledPhiAtVtx,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       eledEtaSeedAtVtx,           ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleBrem,                    ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<float>,       elePFChIso,                 ## __VA_ARGS__)     \
    ACTION(sv<float>,       elePFPhoIso,                ## __VA_ARGS__)     \
    ACTION(sv<float>,       elePFNeuIso,                ## __VA_ARGS__)     \
    ACTION(sv<float>,       elePFPUIso,                 ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<int>,         NEcalClusters,              ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleR9,                      ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleE3x3,                    ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleE5x5,                    ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleR9Full5x5,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleE3x3Full5x5,             ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleE5x5Full5x5,             ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedEn,                  ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedEta,                 ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedPhi,                 ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedCryEta,              ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedCryPhi,              ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedCryIeta,             ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedCryIphi,             ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedE3x3,                ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedE5x5,                ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSEE,                     ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSPP,                     ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSEP,                     ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedEMax,                ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedE2nd,                ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedETop,                ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedEBottom,             ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedELeft,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedERight,              ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedE2x5Max,             ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedE2x5Top,             ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedE2x5Bottom,          ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedE2x5Left,            ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleSeedE2x5Right,           ## __VA_ARGS__)     \

#define B_VAL_ELE_GEN(ACTION, ...)                                          \
    ACTION(int32_t,         nMC,                        ## __VA_ARGS__)     \

#define B_VEC_ELE_GEN(ACTION, ...)                                          \
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

class electrons {
  public:
    electrons(TTree* t, bool gen);

    electrons(electrons const&) = delete;
    electrons& operator=(electrons const&) = delete;
    ~electrons() = default;

    B_VAL_ELE_RECO(DECLVAL)
    B_VAL_ELE_GEN(DECLVAL)
    B_VEC_ELE_RECO(DECLPTR)
    B_VEC_ELE_GEN(DECLPTR)

  private:
    void read(TTree* t);

    bool _gen;
};

#endif  /* ELECTRONS_H */
