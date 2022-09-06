#ifndef   AliAnalysisTaskDeuteron_XeXe_MC_noMult_cxx
#define   AliAnalysisTaskDeuteron_XeXe_MC_noMult_cxx
#include "AliMCEventHandler.h"
#include "AliAODMCParticle.h"
#include "AliAODMCHeader.h"
#include "TClonesArray.h"
#include "AliMCEvent.h"
#include "AliAnalysisTaskSE.h"
//#include "AliMultSelection.h"
#include "AliAnalysisUtils.h"
#include "AliAnalysisTask.h"
#include "AliPIDResponse.h"
#include "AliAODVertex.h"
#include "AliEventCuts.h"
#include "AliAODEvent.h"
#include "AliAODTrack.h"
#include "TObjArray.h"
#include "TVector2.h"
#include "TVector3.h"
#include "TList.h"
#include "TTree.h"
#include "TH1F.h"
#include "TH2F.h"


class AliAnalysisTaskDeuteron_XeXe_MC_noMult : public AliAnalysisTaskSE {

public:
    AliAnalysisTaskDeuteron_XeXe_MC_noMult();
    AliAnalysisTaskDeuteron_XeXe_MC_noMult(const char *name);
    virtual ~AliAnalysisTaskDeuteron_XeXe_MC_noMult();

    virtual void   UserCreateOutputObjects();
    virtual void   UserExec (Option_t *option);

    Bool_t      GetInputEvent ();
    Bool_t      PassedMinimalTrackQualityCuts 		(AliAODTrack *track);
    Bool_t      PassedCandidateSelectiond    		(AliAODTrack *track);
    Double_t    GetDCAxy                      		(AliAODTrack *track);
    Double_t    GetDCAz              		        (AliAODTrack *track);

    Bool_t      PassedTrackQualityCutsNoDCA         (AliAODTrack *track);
    Bool_t      PassedTrackQualityCuts              (AliAODTrack *track);
    Bool_t      IsdCandidate                        (AliAODTrack *track);
    Bool_t      IsCleandCandidate                   (AliAODTrack *track);
    Double_t    Centered_nsigmaTPC                  (AliAODTrack *track);
    Double_t    Centered_nsigmaTOF                  (AliAODTrack *track);
    Bool_t      PassedTOFSelection                  (AliAODTrack *track);
    Bool_t      PassedTPCSelection                  (AliAODTrack *track);





    virtual void   Terminate(Option_t *);


    void SetCentralityRange (Double_t CentralityMin, Double_t CentralityMax)  {

        fCentralityMin = CentralityMin;
        fCentralityMax = CentralityMax;

    }

    void SetEventCuts (Double_t VertexZmin, Double_t VertexZmax, Int_t NumberVertexContributorsMin, const char *CentralityEstimator)  {

        fVertexZmin                     = VertexZmin;
        fVertexZmax                     = VertexZmax;
        fNumberVertexContributorsMin    = NumberVertexContributorsMin;
        fCentralityEstimator            = CentralityEstimator;
    }


    void SetTrackCuts (Double_t PtMin, Double_t PtMax, Double_t EtaMax, Double_t YMax, Int_t NumberClustersITSMin,
                       Int_t NumberClustersTPCMin, Int_t NumberCrossedRowsTPCMin,
                       Double_t CrossedRowsFindableClsMin, Int_t NumberClustersTPCdEdxMin, Double_t ChiSquarePerNDFMax, const char *ITSrequirement,
                       Double_t DCAzMax, Double_t DCAxyMax, Double_t nSigmaTOFmax, Double_t nSigmaTPCmax, Int_t TRDntracklets)  {

        fPtMin                          = PtMin;
        fPtMax                          = PtMax;
        fEtaMax                         = EtaMax;
        fYMax                           = YMax;
        fNumberClustersITSMin           = NumberClustersITSMin;
        fNumberClustersTPCMin           = NumberClustersTPCMin;
        fNumberCrossedRowsTPCMin        = NumberCrossedRowsTPCMin;
        fCrossedRowsFindableClsMin      = CrossedRowsFindableClsMin;
        fNumberClustersTPCdEdxMin       = NumberClustersTPCdEdxMin;
        fChiSquarePerNDFMax             = ChiSquarePerNDFMax;
        fITSrequirement                 = ITSrequirement;
        fDCAzMax                        = DCAzMax;
        fDCAxyMax                       = DCAxyMax;
        fnSigmaTOFmax                   = nSigmaTOFmax;
        fnSigmaTPCmax                   = nSigmaTPCmax;
        fTRDntracklets                  = TRDntracklets;
          }

    void RecalibrationTPCandTOF (Double_t par0_mean_TPC, Double_t par1_mean_TPC, Double_t par0_sigma_TPC, Double_t par0_mean_TOF, Double_t par1_mean_TOF, Double_t par0_sigma_TOF, Double_t par1_sigma_TOF )  {

        fpar0_mean_TPC                  = par0_mean_TPC;
        fpar1_mean_TPC                  = par1_mean_TPC;
        fpar0_sigma_TPC                 = par0_sigma_TPC;
        fpar0_mean_TOF                  = par0_mean_TOF;
        fpar1_mean_TOF                  = par1_mean_TOF;
        fpar0_sigma_TOF                 = par0_sigma_TOF;
        fpar1_sigma_TOF                 = par1_sigma_TOF;



    }


private:
    AliAODEvent       *fAODevent;//!
    AliMCEvent        *fMCevent;//!
    AliPIDResponse    *fPIDResponse;//!
    AliEventCuts       fAODeventCuts;//
    AliAnalysisUtils  *fUtils;//!
    TList             *fOutputList;//!
    TList             *fQAList;//!
    AliAODMCHeader    *fAODMCHeader;//!
    TClonesArray      *fAODArrayMCParticles;//!
    AliMCEventHandler *fMCEventHandler;//!
    TTree             *reducedTree_gen_d;//!
    TTree             *reducedTree_rec_d;//!



    Double_t    fCentralityMin;//
    Double_t    fCentralityMax;//
    Double_t    fVertexZmin;//
    Double_t    fVertexZmax;//
    Int_t       fNumberVertexContributorsMin;//
    const char *fCentralityEstimator;//
    Double_t    fPtMin;//
    Double_t    fPtMax;//
    Double_t    fEtaMax;//
    Double_t    fYMax;//
    Int_t       fNumberClustersITSMin;//
    Int_t       fNumberClustersTPCMin;//
    Int_t       fNumberCrossedRowsTPCMin;//
    Double_t    fCrossedRowsFindableClsMin;//
    Int_t       fNumberClustersTPCdEdxMin;//
    Double_t    fChiSquarePerNDFMax;//
    const char *fITSrequirement;//
    Double_t    fDCAzMax;//
    Double_t    fDCAxyMax;//
    Double_t    fnSigmaTOFmax;//
    Double_t    fnSigmaTPCmax;//
    Int_t       fTRDntracklets;//
    Double_t    fpar0_mean_TPC;//
    Double_t    fpar1_mean_TPC;//
    Double_t    fpar0_sigma_TPC;//
    Double_t    fpar0_mean_TOF;//
    Double_t    fpar1_mean_TOF;//
    Double_t    fpar0_sigma_TOF;//
    Double_t    fpar1_sigma_TOF;//

    //Histograms for d
    TH1F        *histoNumberOfEvents;//!
    TH2F        *histoNsigmaTPCd_vs_pt;//!
    TH2F        *histoNsigmaTOFd_vs_pt;//!
    TH2F        *histoNsigmaTPCantid_vs_pt;//!
    TH2F        *histoNsigmaTOFantid_vs_pt;//!
    TH2F        *histoNsigmaTPCd_vs_pt_centered;//!
    TH2F        *histoNsigmaTPCantid_vs_pt_centered;//!
    TH2F        *histoNsigmaTOFd_vs_pt_centered;//!
    TH2F        *histoNsigmaTOFantid_vs_pt_centered;//!
    TH2F        *histoDCAxyd_vs_pt;//!
    TH2F        *histoDCAxyAntid_vs_pt;//!
    TH2F        *histoNsigmaTOFd_vs_pt_trd;//!
    TH2F        *histoNsigmaTOFantid_vs_pt_trd;//!
    TH2F        *histoNsigmaTPCd_vs_p;//!
    TH2F        *histoNsigmaTPCantid_vs_p;//!
    TH2F        *histoNsigmaTOFd_vs_p;//!
    TH2F        *histoNsigmaTOFantid_vs_p;//!
    TH2F        *histoNsigmaTPCd_vs_p_notof;//!
    TH2F        *histoNsigmaTPCantid_vs_p_notof;//!


    // Tree variables
    Float_t centrality;//
    Float_t multPercentile_V0M;//
    Int_t   particleType;
    Float_t xVertex;//
    Float_t yVertex;//
    Float_t zVertex;//
    Int_t   ID_event;//
    Int_t   lp;//
    Float_t px;//
    Float_t py;//
    Float_t pz;//
    Float_t pt;//
    Float_t pt_particle;//
    Float_t pz_particle;//
    Float_t deltapt;//
    Float_t deltapz;//
    Int_t   charge;//
    Double_t dcaxy;//
    Double_t dcaz;//
    Int_t   trackType;//
    Int_t   nTPC_Clusters;//
    Int_t   nITS_Clusters;//
    Int_t   nTPC_Clusters_dEdx;//
    Int_t   nTPC_FindableClusters;//
    Int_t   nTPC_CrossedRows;//
    Int_t   HasPointOnITSLayer0;//
    Int_t   HasPointOnITSLayer1;//
    Int_t   HasPointOnITSLayer2;//
    Int_t   HasPointOnITSLayer3;//
    Int_t   HasPointOnITSLayer4;//
    Int_t   HasPointOnITSLayer5;//
    Float_t chi2_NDF;//
    Float_t chi2_ITS;//
    Float_t nSigmaITS;
    Float_t nSigmaTPC;//
    Float_t nSigmaTOF;//
    Int_t   PrimaryParticle;//
    Int_t   SecondaryMaterial;//
    Int_t   SecondaryDecay;//
    Int_t   PrimaryTrack;//
    Double_t TPC_signal;//
    Double_t ITS_signal;//
    Double_t TOF_signal;//
    Int_t   TRDntracklets;//
    Int_t   hasTOFhit;//



    AliAnalysisTaskDeuteron_XeXe_MC_noMult(const AliAnalysisTaskDeuteron_XeXe_MC_noMult&);
    AliAnalysisTaskDeuteron_XeXe_MC_noMult& operator=(const AliAnalysisTaskDeuteron_XeXe_MC_noMult&);
    ClassDef(AliAnalysisTaskDeuteron_XeXe_MC_noMult, 1);
};
#endif