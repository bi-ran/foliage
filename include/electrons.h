#ifndef ELECTRONS_H
#define ELECTRONS_H

#include "foliage.h"

#include "TTree.h"

#include <vector>

#define B_VAL_ELE_RECO(ACTION, ...)                                         \
    ACTION(float,           rho,                        ## __VA_ARGS__)     \
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
    ACTION(sv<float>,       eleIP3D,                    ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleIP3DErr,                 ## __VA_ARGS__)     \
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
    ACTION(sv<int>,         eleConvVeto,                ## __VA_ARGS__)     \
    ACTION(sv<float>,       eledEtaAtVtx,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       eledPhiAtVtx,               ## __VA_ARGS__)     \
    ACTION(sv<float>,       eledEtaSeedAtVtx,           ## __VA_ARGS__)     \
    ACTION(sv<float>,       eleBrem,                    ## __VA_ARGS__)     \
                                                                            \
    ACTION(sv<float>,       elePFChIso,                 ## __VA_ARGS__)     \
    ACTION(sv<float>,       elePFPhoIso,                ## __VA_ARGS__)     \
    ACTION(sv<float>,       elePFNeuIso,                ## __VA_ARGS__)     \
    ACTION(sv<float>,       elePFPUIso,                 ## __VA_ARGS__)     \

class electrons {
  public:
    electrons(TTree* t);

    electrons(electrons const&) = delete;
    electrons& operator=(electrons const&) = delete;
    ~electrons() = default;

    B_VAL_ELE_RECO(DECLVAL)
    B_VEC_ELE_RECO(DECLPTR)

  private:
    void read(TTree* t);
};

#endif  /* ELECTRONS_H */
