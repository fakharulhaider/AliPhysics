/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. */
/* See cxx source for full Copyright notice */
/* $Id$ */

#ifndef AliAnalysisTaskNanoMUON_H
#define AliAnalysisTaskNanoMUON_H

#include <AliAnalysisTaskSE.h>

class AliMuonTrackCuts; 	// Include class for standard muon tack cuts


class AliAnalysisTaskNanoMUON : public AliAnalysisTaskSE  
{
public:
                            AliAnalysisTaskNanoMUON();
                            AliAnalysisTaskNanoMUON(const char *name);
    virtual                 ~AliAnalysisTaskNanoMUON();

    virtual void            UserCreateOutputObjects();
    virtual void            UserExec(Option_t* option);
    virtual void            Terminate(Option_t* option);
    virtual void   			NotifyRun();								  // Implement the Notify run to search for the new parameters at each new runs
	void 					TwoMuonAna(Int_t *pos, Int_t *neg);			  // Analyses two muons and extracs dimuon information
	void 					TwoMCMuonAna(Int_t *MCpos, Int_t *MCneg);	  // Analyses two MC muons and extracs MC dimuon information
	void 					SetPeriod(TString period){fPeriod = period;}  
	void 					SetTrigger(TString trigger){fTrigger = trigger;} 
	void 					SetMC(Bool_t flag){fIsMC = flag;}	
	void 					SetScaling(Bool_t flag){fIsScalingOn = flag;}	
	void 					SetRunAndLumi(Int_t run, Double_t lumi){
								fMapRunAndLumi[run] = lumi;
  								fMapAnalysedMC[run] = 0;
							}
	void 					PostAllData();	

    AliMuonTrackCuts* 		fMuonTrackCuts; 					// Use the class as a data member

private:
	TString 				fPeriod;
	TString 				fTrigger;
	Bool_t 					fIsMC;
	Bool_t 					fIsScalingOn;

    AliAODEvent*            fAOD;       		//! input event
    AliMCEvent*				fMC;				//! input MC event

    TList*                  fOutputList; 		//! output list
    TH1F*                   fCounterH; 			//! counter for events passing each cut	
    TH2F*                   fNumberMuonsH; 		//! count good muons per event
    TH2F*                   fNumberMCMuonsH;	//! count MC muons per event
	// TH2F*                   fRAbsMuonH; 		//! distribution of RAbsMuon for selected events
	// TH2F*                   fMuMuMassPtH; 		//! kinematics of dimouns	
    std::map<Int_t,Double_t> 	fMapRunAndLumi;
  	std::map<Int_t,Double_t> 	fMapAnalysedMC;

	TTree *fRecTree; 			//! analysis tree
	Int_t fRunNum;
	UInt_t fL0inputs;
	Int_t fTracklets;
	Float_t fZNCEnergy; 
	Float_t fZNAEnergy;
	// Float_t fZPCEnergy; 
	// Float_t fZPAEnergy;
	Float_t fZNATDC[4];
	Float_t fZNCTDC[4];
	// Float_t fZPATDC[4];
	// Float_t fZPCTDC[4];
	Int_t fV0ADecision; 
	Int_t fV0CDecision;
	Int_t fV0AFiredCells; 
	Int_t fV0CFiredCells; 
	Bool_t fV0AOfflineTrigger[32];
	Bool_t fV0COfflineTrigger[32];
	Int_t fADADecision; 
	Int_t fADCDecision;
	Int_t fIsZNAFired;
	Int_t fIsZNCFired;
  	// TBits fIR1Map;
  	// TBits fIR2Map;
	Float_t fMuMuPt; 
	Float_t fMuMuPhi;
	Float_t fMuMuY; 
	Float_t fMuMuM;
	Float_t fMuPt1; 
	Float_t fMuPt2;
	Float_t fMuEta1; 
	Float_t fMuEta2;
	Float_t fMuPhi1; 
	Float_t fMuPhi2;
	// Int_t fMuQ1; 
	// Int_t fMuQ2;
	Float_t fGenMuMuPt; 
	Float_t fGenMuMuPhi;
	Float_t fGenMuMuY; 
	Float_t fGenMuMuM;
	Float_t fGenMuPt1; 
	Float_t fGenMuPt2;
	Float_t fGenMuEta1; 
	Float_t fGenMuEta2;
	Float_t fGenMuPhi1; 
	Float_t fGenMuPhi2;
	Int_t fCMUP6Decision;
	Int_t fCMUP10Decision;
	Int_t fCMUP11Decision;

	TClonesArray *fGenPart; 	//! MC particle object
	TTree *fGenTree; 			//! MC tree
	Int_t fMCRunNum;
	Float_t fMCMuMuPt; 
	Float_t fMCMuMuPhi;
	Float_t fMCMuMuY; 
	Float_t fMCMuMuM;
	Float_t fMCMuPt1; 
	Float_t fMCMuPt2;
	Float_t fMCMuEta1; 
	Float_t fMCMuEta2;
	Float_t fMCMuPhi1; 
	Float_t fMCMuPhi2;
	// Int_t fMCMuPDG1; 
	// Int_t fMCMuPDG2;

	TTree *fTrgTree; 			//! trigger info tree
	Int_t fTrgRunNum;
	Int_t fCMUP6;
	Int_t fCMUP10;
	Int_t fCMUP11;


    AliAnalysisTaskNanoMUON(const AliAnalysisTaskNanoMUON&); // not implemented
    AliAnalysisTaskNanoMUON& operator=(const AliAnalysisTaskNanoMUON&); // not implemented

    ClassDef(AliAnalysisTaskNanoMUON, 1);
};

#endif
