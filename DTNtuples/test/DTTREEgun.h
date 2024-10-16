//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Nov 18 16:50:55 2022 by ROOT version 6.22/09
// from TTree DTTREEgun/DT Tree
// found on file: DTDPGNtuple_12_3_0_Phase2_Simulation_PU200_AM.root
//////////////////////////////////////////////////////////

#ifndef DTTREEgun_h
#define DTTREEgun_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "TClonesArray.h"
#include "vector"
#include "vector"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"

class DTTREEgun {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
 
/*   TFile *f = new TFile("test.root","RECREATE");
 
   TH2F *h_segT0VSLocY[20];
   TH1F *h_segT0_rings[20];
   TH2F *h_trigQualVST0;
   TH1F *h_trigT0_rings[20];
   TH2F *h_trigT0VSLocY[20];
*/    
// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          gen_nGenParts;
   vector<int>     *gen_pdgId;
   vector<float>   *gen_pt;
   vector<float>   *gen_phi;
   vector<float>   *gen_eta;
   vector<short>   *gen_charge;
   Int_t           event_runNumber;
   Int_t           event_lumiBlock;
   Long64_t        event_eventNumber;
   ULong64_t       event_timeStamp;
   Int_t           event_bunchCrossing;
   Long64_t        event_orbitNumber;
   UInt_t          digi_nDigis;
   vector<short>   *digi_wheel;
   vector<short>   *digi_sector;
   vector<short>   *digi_station;
   vector<short>   *digi_superLayer;
   vector<short>   *digi_layer;
   vector<short>   *digi_wire;
   vector<float>   *digi_time;
   UInt_t          ph2Digi_nDigis;
   vector<short>   *ph2Digi_wheel;
   vector<short>   *ph2Digi_sector;
   vector<short>   *ph2Digi_station;
   vector<short>   *ph2Digi_superLayer;
   vector<short>   *ph2Digi_layer;
   vector<short>   *ph2Digi_wire;
   vector<float>   *ph2Digi_time;
   UInt_t          seg_nSegments;
   vector<short>   *seg_wheel;
   vector<short>   *seg_sector;
   vector<short>   *seg_station;
   vector<short>   *seg_hasPhi;
   vector<short>   *seg_hasZed;
   vector<float>   *seg_posLoc_x;
   vector<float>   *seg_posLoc_y;
   vector<float>   *seg_posLoc_z;
   vector<float>   *seg_dirLoc_x;
   vector<float>   *seg_dirLoc_y;
   vector<float>   *seg_dirLoc_z;
   vector<float>   *seg_posLoc_x_SL1;
   vector<float>   *seg_posLoc_x_SL3;
   vector<float>   *seg_posLoc_x_midPlane;
   vector<float>   *seg_posGlb_phi;
   vector<float>   *seg_posGlb_phi_midPlane;
   vector<float>   *seg_posGlb_phi_SL1;
   vector<float>   *seg_posGlb_phi_SL3;
   vector<float>   *seg_posGlb_eta;
   vector<float>   *seg_dirGlb_phi;
   vector<float>   *seg_dirGlb_eta;
   TClonesArray    *seg_hitsExpPos;
   TClonesArray    *seg_hitsExpPosCh;
   TClonesArray    *seg_hitsExpWire;
   vector<float>   *seg_phi_t0;
   vector<float>   *seg_phi_vDrift;
   vector<float>   *seg_phi_normChi2;
   vector<short>   *seg_phi_nHits;
   TClonesArray    *seg_phiHits_pos;
   TClonesArray    *seg_phiHits_posCh;
   TClonesArray    *seg_phiHits_posErr;
   TClonesArray    *seg_phiHits_side;
   TClonesArray    *seg_phiHits_wire;
   TClonesArray    *seg_phiHits_wirePos;
   TClonesArray    *seg_phiHits_layer;
   TClonesArray    *seg_phiHits_superLayer;
   TClonesArray    *seg_phiHits_time;
   TClonesArray    *seg_phiHits_timeCali;
   vector<float>   *seg_z_normChi2;
   vector<short>   *seg_z_nHits;
   TClonesArray    *seg_zHits_pos;
   TClonesArray    *seg_zHits_posCh;
   TClonesArray    *seg_zHits_posErr;
   TClonesArray    *seg_zHits_side;
   TClonesArray    *seg_zHits_wire;
   TClonesArray    *seg_zHits_wirePos;
   TClonesArray    *seg_zHits_layer;
   TClonesArray    *seg_zHits_time;
   TClonesArray    *seg_zHits_timeCali;
   UInt_t          ph2Seg_nSegments;
   vector<short>   *ph2Seg_wheel;
   vector<short>   *ph2Seg_sector;
   vector<short>   *ph2Seg_station;
   vector<short>   *ph2Seg_hasPhi;
   vector<short>   *ph2Seg_hasZed;
   vector<float>   *ph2Seg_posLoc_x;
   vector<float>   *ph2Seg_posLoc_y;
   vector<float>   *ph2Seg_posLoc_z;
   vector<float>   *ph2Seg_dirLoc_x;
   vector<float>   *ph2Seg_dirLoc_y;
   vector<float>   *ph2Seg_dirLoc_z;
   vector<float>   *ph2Seg_posLoc_x_SL1;
   vector<float>   *ph2Seg_posLoc_x_SL3;
   vector<float>   *ph2Seg_posLoc_x_midPlane;
   vector<float>   *ph2Seg_posGlb_phi;
   vector<float>   *ph2Seg_posGlb_phi_midPlane;
   vector<float>   *ph2Seg_posGlb_phi_SL1;
   vector<float>   *ph2Seg_posGlb_phi_SL3;
   vector<float>   *ph2Seg_posGlb_eta;
   vector<float>   *ph2Seg_dirGlb_phi;
   vector<float>   *ph2Seg_dirGlb_eta;
   TClonesArray    *ph2Seg_hitsExpPos;
   TClonesArray    *ph2Seg_hitsExpPosCh;
   TClonesArray    *ph2Seg_hitsExpWire;
   vector<float>   *ph2Seg_phi_t0;
   vector<float>   *ph2Seg_phi_vDrift;
   vector<float>   *ph2Seg_phi_normChi2;
   vector<short>   *ph2Seg_phi_nHits;
   TClonesArray    *ph2Seg_phiHits_pos;
   TClonesArray    *ph2Seg_phiHits_posCh;
   TClonesArray    *ph2Seg_phiHits_posErr;
   TClonesArray    *ph2Seg_phiHits_side;
   TClonesArray    *ph2Seg_phiHits_wire;
   TClonesArray    *ph2Seg_phiHits_wirePos;
   TClonesArray    *ph2Seg_phiHits_layer;
   TClonesArray    *ph2Seg_phiHits_superLayer;
   TClonesArray    *ph2Seg_phiHits_time;
   TClonesArray    *ph2Seg_phiHits_timeCali;
   vector<float>   *ph2Seg_z_normChi2;
   vector<short>   *ph2Seg_z_nHits;
   TClonesArray    *ph2Seg_zHits_pos;
   TClonesArray    *ph2Seg_zHits_posCh;
   TClonesArray    *ph2Seg_zHits_posErr;
   TClonesArray    *ph2Seg_zHits_side;
   TClonesArray    *ph2Seg_zHits_wire;
   TClonesArray    *ph2Seg_zHits_wirePos;
   TClonesArray    *ph2Seg_zHits_layer;
   TClonesArray    *ph2Seg_zHits_time;
   TClonesArray    *ph2Seg_zHits_timeCali;
   UInt_t          ph2TpgPhiEmuAm_nTrigs;
   vector<short>   *ph2TpgPhiEmuAm_wheel;
   vector<short>   *ph2TpgPhiEmuAm_sector;
   vector<short>   *ph2TpgPhiEmuAm_station;
   vector<short>   *ph2TpgPhiEmuAm_quality;
   vector<short>   *ph2TpgPhiEmuAm_superLayer;
   vector<short>   *ph2TpgPhiEmuAm_rpcFlag;
   vector<int>     *ph2TpgPhiEmuAm_chi2;
   vector<int>     *ph2TpgPhiEmuAm_phi;
   vector<int>     *ph2TpgPhiEmuAm_phiB;
   vector<int>     *ph2TpgPhiEmuAm_phiCMSSW;
   vector<int>     *ph2TpgPhiEmuAm_phiBCMSSW;
   vector<float>   *ph2TpgPhiEmuAm_posLoc_x_raw;
   vector<float>   *ph2TpgPhiEmuAm_posLoc_x;
   vector<float>   *ph2TpgPhiEmuAm_dirLoc_phi;
   vector<int>     *ph2TpgPhiEmuAm_BX;
   vector<int>     *ph2TpgPhiEmuAm_t0;
   vector<short>   *ph2TpgPhiEmuAm_index;
   vector<vector<short> > *ph2TpgPhiEmuAm_pathWireId;
   vector<vector<int> > *ph2TpgPhiEmuAm_pathTDC;
   vector<vector<short> > *ph2TpgPhiEmuAm_pathLat;
   UInt_t          ph2TpgThetaEmuAm_nTrigs;
   vector<short>   *ph2TpgThetaEmuAm_wheel;
   vector<short>   *ph2TpgThetaEmuAm_sector;
   vector<short>   *ph2TpgThetaEmuAm_station;
   vector<short>   *ph2TpgThetaEmuAm_quality;
   vector<short>   *ph2TpgThetaEmuAm_rpcFlag;
   vector<int>     *ph2TpgThetaEmuAm_chi2;
   vector<int>     *ph2TpgThetaEmuAm_z;
   vector<int>     *ph2TpgThetaEmuAm_k;
   vector<int>     *ph2TpgThetaEmuAm_BX;
   vector<int>     *ph2TpgThetaEmuAm_t0;
   vector<float>     *ph2TpgThetaEmuAm_posLoc_y_raw;
   vector<short>   *ph2TpgThetaEmuAm_index;

   // List of branches
   TBranch        *b_gen_nGenParts;   //!
   TBranch        *b_gen_pdgId;   //!
   TBranch        *b_gen_pt;   //!
   TBranch        *b_gen_phi;   //!
   TBranch        *b_gen_eta;   //!
   TBranch        *b_gen_charge;   //!
   TBranch        *b_event_runNumber;   //!
   TBranch        *b_event_lumiBlock;   //!
   TBranch        *b_event_eventNumber;   //!
   TBranch        *b_event_timeStamp;   //!
   TBranch        *b_event_bunchCrossing;   //!
   TBranch        *b_event_orbitNumber;   //!
   TBranch        *b_digi_nDigis;   //!
   TBranch        *b_digi_wheel;   //!
   TBranch        *b_digi_sector;   //!
   TBranch        *b_digi_station;   //!
   TBranch        *b_digi_superLayer;   //!
   TBranch        *b_digi_layer;   //!
   TBranch        *b_digi_wire;   //!
   TBranch        *b_digi_time;   //!
   TBranch        *b_ph2Digi_nDigis;   //!
   TBranch        *b_ph2Digi_wheel;   //!
   TBranch        *b_ph2Digi_sector;   //!
   TBranch        *b_ph2Digi_station;   //!
   TBranch        *b_ph2Digi_superLayer;   //!
   TBranch        *b_ph2Digi_layer;   //!
   TBranch        *b_ph2Digi_wire;   //!
   TBranch        *b_ph2Digi_time;   //!
   TBranch        *b_seg_nSegments;   //!
   TBranch        *b_seg_wheel;   //!
   TBranch        *b_seg_sector;   //!
   TBranch        *b_seg_station;   //!
   TBranch        *b_seg_hasPhi;   //!
   TBranch        *b_seg_hasZed;   //!
   TBranch        *b_seg_posLoc_x;   //!
   TBranch        *b_seg_posLoc_y;   //!
   TBranch        *b_seg_posLoc_z;   //!
   TBranch        *b_seg_dirLoc_x;   //!
   TBranch        *b_seg_dirLoc_y;   //!
   TBranch        *b_seg_dirLoc_z;   //!
   TBranch        *b_seg_posLoc_x_SL1;   //!
   TBranch        *b_seg_posLoc_x_SL3;   //!
   TBranch        *b_seg_posLoc_x_midPlane;   //!
   TBranch        *b_seg_posGlb_phi;   //!
   TBranch        *b_seg_posGlb_phi_midPlane;   //!
   TBranch        *b_seg_posGlb_phi_SL1;   //!
   TBranch        *b_seg_posGlb_phi_SL3;   //!
   TBranch        *b_seg_posGlb_eta;   //!
   TBranch        *b_seg_dirGlb_phi;   //!
   TBranch        *b_seg_dirGlb_eta;   //!
   TBranch        *b_seg_hitsExpPos;   //!
   TBranch        *b_seg_hitsExpPosCh;   //!
   TBranch        *b_seg_hitsExpWire;   //!
   TBranch        *b_seg_phi_t0;   //!
   TBranch        *b_seg_phi_vDrift;   //!
   TBranch        *b_seg_phi_normChi2;   //!
   TBranch        *b_seg_phi_nHits;   //!
   TBranch        *b_seg_phiHits_pos;   //!
   TBranch        *b_seg_phiHits_posCh;   //!
   TBranch        *b_seg_phiHits_posErr;   //!
   TBranch        *b_seg_phiHits_side;   //!
   TBranch        *b_seg_phiHits_wire;   //!
   TBranch        *b_seg_phiHits_wirePos;   //!
   TBranch        *b_seg_phiHits_layer;   //!
   TBranch        *b_seg_phiHits_superLayer;   //!
   TBranch        *b_seg_phiHits_time;   //!
   TBranch        *b_seg_phiHits_timeCali;   //!
   TBranch        *b_seg_z_normChi2;   //!
   TBranch        *b_seg_z_nHits;   //!
   TBranch        *b_seg_zHits_pos;   //!
   TBranch        *b_seg_zHits_posCh;   //!
   TBranch        *b_seg_zHits_posErr;   //!
   TBranch        *b_seg_zHits_side;   //!
   TBranch        *b_seg_zHits_wire;   //!
   TBranch        *b_seg_zHits_wirePos;   //!
   TBranch        *b_seg_zHits_layer;   //!
   TBranch        *b_seg_zHits_time;   //!
   TBranch        *b_seg_zHits_timeCali;   //!
   TBranch        *b_ph2Seg_nSegments;   //!
   TBranch        *b_ph2Seg_wheel;   //!
   TBranch        *b_ph2Seg_sector;   //!
   TBranch        *b_ph2Seg_station;   //!
   TBranch        *b_ph2Seg_hasPhi;   //!
   TBranch        *b_ph2Seg_hasZed;   //!
   TBranch        *b_ph2Seg_posLoc_x;   //!
   TBranch        *b_ph2Seg_posLoc_y;   //!
   TBranch        *b_ph2Seg_posLoc_z;   //!
   TBranch        *b_ph2Seg_dirLoc_x;   //!
   TBranch        *b_ph2Seg_dirLoc_y;   //!
   TBranch        *b_ph2Seg_dirLoc_z;   //!
   TBranch        *b_ph2Seg_posLoc_x_SL1;   //!
   TBranch        *b_ph2Seg_posLoc_x_SL3;   //!
   TBranch        *b_ph2Seg_posLoc_x_midPlane;   //!
   TBranch        *b_ph2Seg_posGlb_phi;   //!
   TBranch        *b_ph2Seg_posGlb_phi_midPlane;   //!
   TBranch        *b_ph2Seg_posGlb_phi_SL1;   //!
   TBranch        *b_ph2Seg_posGlb_phi_SL3;   //!
   TBranch        *b_ph2Seg_posGlb_eta;   //!
   TBranch        *b_ph2Seg_dirGlb_phi;   //!
   TBranch        *b_ph2Seg_dirGlb_eta;   //!
   TBranch        *b_ph2Seg_hitsExpPos;   //!
   TBranch        *b_ph2Seg_hitsExpPosCh;   //!
   TBranch        *b_ph2Seg_hitsExpWire;   //!
   TBranch        *b_ph2Seg_phi_t0;   //!
   TBranch        *b_ph2Seg_phi_vDrift;   //!
   TBranch        *b_ph2Seg_phi_normChi2;   //!
   TBranch        *b_ph2Seg_phi_nHits;   //!
   TBranch        *b_ph2Seg_phiHits_pos;   //!
   TBranch        *b_ph2Seg_phiHits_posCh;   //!
   TBranch        *b_ph2Seg_phiHits_posErr;   //!
   TBranch        *b_ph2Seg_phiHits_side;   //!
   TBranch        *b_ph2Seg_phiHits_wire;   //!
   TBranch        *b_ph2Seg_phiHits_wirePos;   //!
   TBranch        *b_ph2Seg_phiHits_layer;   //!
   TBranch        *b_ph2Seg_phiHits_superLayer;   //!
   TBranch        *b_ph2Seg_phiHits_time;   //!
   TBranch        *b_ph2Seg_phiHits_timeCali;   //!
   TBranch        *b_ph2Seg_z_normChi2;   //!
   TBranch        *b_ph2Seg_z_nHits;   //!
   TBranch        *b_ph2Seg_zHits_pos;   //!
   TBranch        *b_ph2Seg_zHits_posCh;   //!
   TBranch        *b_ph2Seg_zHits_posErr;   //!
   TBranch        *b_ph2Seg_zHits_side;   //!
   TBranch        *b_ph2Seg_zHits_wire;   //!
   TBranch        *b_ph2Seg_zHits_wirePos;   //!
   TBranch        *b_ph2Seg_zHits_layer;   //!
   TBranch        *b_ph2Seg_zHits_time;   //!
   TBranch        *b_ph2Seg_zHits_timeCali;   //!
   TBranch        *b_ph2TpgPhiEmuAm_nTrigs;   //!
   TBranch        *b_ph2TpgPhiEmuAm_wheel;   //!
   TBranch        *b_ph2TpgPhiEmuAm_sector;   //!
   TBranch        *b_ph2TpgPhiEmuAm_station;   //!
   TBranch        *b_ph2TpgPhiEmuAm_quality;   //!
   TBranch        *b_ph2TpgPhiEmuAm_superLayer;   //!
   TBranch        *b_ph2TpgPhiEmuAm_rpcFlag;   //!
   TBranch        *b_ph2TpgPhiEmuAm_chi2;   //!
   TBranch        *b_ph2TpgPhiEmuAm_phi;   //!
   TBranch        *b_ph2TpgPhiEmuAm_phiB;   //!
   TBranch        *b_ph2TpgPhiEmuAm_phiCMSSW;   //!
   TBranch        *b_ph2TpgPhiEmuAm_phiBCMSSW;   //!
   TBranch        *b_ph2TpgPhiEmuAm_posLoc_x_raw;   //!
   TBranch        *b_ph2TpgPhiEmuAm_posLoc_x;   //!
   TBranch        *b_ph2TpgPhiEmuAm_dirLoc_phi;   //!
   TBranch        *b_ph2TpgPhiEmuAm_BX;   //!
   TBranch        *b_ph2TpgPhiEmuAm_t0;   //!
   TBranch        *b_ph2TpgPhiEmuAm_index;   //!
   TBranch        *b_ph2TpgPhiEmuAm_pathWireId;   //!
   TBranch        *b_ph2TpgPhiEmuAm_pathTDC;   //!
   TBranch        *b_ph2TpgPhiEmuAm_pathLat;   //!
   TBranch        *b_ph2TpgThetaEmuAm_nTrigs;   //!
   TBranch        *b_ph2TpgThetaEmuAm_wheel;   //!
   TBranch        *b_ph2TpgThetaEmuAm_sector;   //!
   TBranch        *b_ph2TpgThetaEmuAm_station;   //!
   TBranch        *b_ph2TpgThetaEmuAm_quality;   //!
   TBranch        *b_ph2TpgThetaEmuAm_rpcFlag;   //!
   TBranch        *b_ph2TpgThetaEmuAm_chi2;   //!
   TBranch        *b_ph2TpgThetaEmuAm_z;   //!
   TBranch        *b_ph2TpgThetaEmuAm_k;   //!
   TBranch        *b_ph2TpgThetaEmuAm_BX;   //!
   TBranch        *b_ph2TpgThetaEmuAm_t0;   //!
   TBranch        *b_ph2TpgThetaEmuAm_index;   //!
   TBranch        *b_ph2TpgThetaEmuAm_posLoc_y_raw; //~

   DTTREEgun(TTree *tree=0);
   virtual ~DTTREEgun();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   Int_t BestSeg(Int_t index, Int_t iStationToLook);
   Int_t BestTrig(Int_t index, Int_t iStationToLook, Int_t wheel, Int_t trigQual);
   Int_t BestTrigZ(Int_t index, Int_t iStationToLook, Int_t wheel, Int_t trigQual);

};

#endif

#ifdef DTTREEgun_cxx
DTTREEgun::DTTREEgun(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
//      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DTDPGNtuple_12_3_0_Phase2_Simulation_PU200_AM.root");
//      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DTDPGNtuple_12_3_0_new_Phase2_Simulation_ParticleGun_thermalNeutrons_PU200_AM.root");
//      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DTDPGNtuple_12_3_0_new_Phase2_Simulation_ParticleGun_thermalNeutrons_PU200_DTntupleExtra.root");
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("rossinQcut0.root");
//        TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DTDPGNtuple_12_3_0_new_Phase2_Simulation_ParticleGun_thermalNeutrons_PU200_DTntupleExtra_TPcorr.root");
      if (!f || !f->IsOpen()) {
//         f = new TFile("DTDPGNtuple_12_3_0_Phase2_Simulation_PU200_AM.root");
//           f = new TFile("DTDPGNtuple_12_3_0_new_Phase2_Simulation_ParticleGun_thermalNeutrons_PU200_AM.root");
//           f = new TFile("DTDPGNtuple_12_3_0_new_Phase2_Simulation_ParticleGun_thermalNeutrons_PU200_DTntupleExtra.root");
	   f = new TFile("rossinQcut0.root");
//             f = new TFile("DTDPGNtuple_12_3_0_new_Phase2_Simulation_ParticleGun_thermalNeutrons_PU200_DTntupleExtra_TPcorr.root");           
      }
//      TDirectory * dir = (TDirectory*)f->Get("DTDPGNtuple_12_3_0_Phase2_Simulation_PU200_AM.root:/dtNtupleProducer");
//      TDirectory * dir = (TDirectory*)f->Get("DTDPGNtuple_12_3_0_new_Phase2_Simulation_ParticleGun_thermalNeutrons_PU200_AM.root:/dtNtupleProducer");
//      TDirectory * dir = (TDirectory*)f->Get("DTDPGNtuple_12_3_0_new_Phase2_Simulation_ParticleGun_thermalNeutrons_PU200_DTntupleExtra.root:/dtNtupleProducer");
      TDirectory * dir = (TDirectory*)f->Get("rossinQcut0.root:/dtNtupleProducer");
//       TDirectory * dir = (TDirectory*)f->Get("DTDPGNtuple_12_3_0_new_Phase2_Simulation_ParticleGun_thermalNeutrons_PU200_DTntupleExtra_TPcorr.root:/dtNtupleProducer");   
      dir->GetObject("DTTREE",tree);

   }
   Init(tree);
}

DTTREEgun::~DTTREEgun()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DTTREEgun::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DTTREEgun::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void DTTREEgun::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   gen_pdgId = 0;
   gen_pt = 0;
   gen_phi = 0;
   gen_eta = 0;
   gen_charge = 0;
   digi_wheel = 0;
   digi_sector = 0;
   digi_station = 0;
   digi_superLayer = 0;
   digi_layer = 0;
   digi_wire = 0;
   digi_time = 0;
   ph2Digi_wheel = 0;
   ph2Digi_sector = 0;
   ph2Digi_station = 0;
   ph2Digi_superLayer = 0;
   ph2Digi_layer = 0;
   ph2Digi_wire = 0;
   ph2Digi_time = 0;
   seg_wheel = 0;
   seg_sector = 0;
   seg_station = 0;
   seg_hasPhi = 0;
   seg_hasZed = 0;
   seg_posLoc_x = 0;
   seg_posLoc_y = 0;
   seg_posLoc_z = 0;
   seg_dirLoc_x = 0;
   seg_dirLoc_y = 0;
   seg_dirLoc_z = 0;
   seg_posLoc_x_SL1 = 0;
   seg_posLoc_x_SL3 = 0;
   seg_posLoc_x_midPlane = 0;
   seg_posGlb_phi = 0;
   seg_posGlb_phi_midPlane = 0;
   seg_posGlb_phi_SL1 = 0;
   seg_posGlb_phi_SL3 = 0;
   seg_posGlb_eta = 0;
   seg_dirGlb_phi = 0;
   seg_dirGlb_eta = 0;
   seg_hitsExpPos = 0;
   seg_hitsExpPosCh = 0;
   seg_hitsExpWire = 0;
   seg_phi_t0 = 0;
   seg_phi_vDrift = 0;
   seg_phi_normChi2 = 0;
   seg_phi_nHits = 0;
   seg_phiHits_pos = 0;
   seg_phiHits_posCh = 0;
   seg_phiHits_posErr = 0;
   seg_phiHits_side = 0;
   seg_phiHits_wire = 0;
   seg_phiHits_wirePos = 0;
   seg_phiHits_layer = 0;
   seg_phiHits_superLayer = 0;
   seg_phiHits_time = 0;
   seg_phiHits_timeCali = 0;
   seg_z_normChi2 = 0;
   seg_z_nHits = 0;
   seg_zHits_pos = 0;
   seg_zHits_posCh = 0;
   seg_zHits_posErr = 0;
   seg_zHits_side = 0;
   seg_zHits_wire = 0;
   seg_zHits_wirePos = 0;
   seg_zHits_layer = 0;
   seg_zHits_time = 0;
   seg_zHits_timeCali = 0;
   ph2Seg_wheel = 0;
   ph2Seg_sector = 0;
   ph2Seg_station = 0;
   ph2Seg_hasPhi = 0;
   ph2Seg_hasZed = 0;
   ph2Seg_posLoc_x = 0;
   ph2Seg_posLoc_y = 0;
   ph2Seg_posLoc_z = 0;
   ph2Seg_dirLoc_x = 0;
   ph2Seg_dirLoc_y = 0;
   ph2Seg_dirLoc_z = 0;
   ph2Seg_posLoc_x_SL1 = 0;
   ph2Seg_posLoc_x_SL3 = 0;
   ph2Seg_posLoc_x_midPlane = 0;
   ph2Seg_posGlb_phi = 0;
   ph2Seg_posGlb_phi_midPlane = 0;
   ph2Seg_posGlb_phi_SL1 = 0;
   ph2Seg_posGlb_phi_SL3 = 0;
   ph2Seg_posGlb_eta = 0;
   ph2Seg_dirGlb_phi = 0;
   ph2Seg_dirGlb_eta = 0;
   ph2Seg_hitsExpPos = 0;
   ph2Seg_hitsExpPosCh = 0;
   ph2Seg_hitsExpWire = 0;
   ph2Seg_phi_t0 = 0;
   ph2Seg_phi_vDrift = 0;
   ph2Seg_phi_normChi2 = 0;
   ph2Seg_phi_nHits = 0;
   ph2Seg_phiHits_pos = 0;
   ph2Seg_phiHits_posCh = 0;
   ph2Seg_phiHits_posErr = 0;
   ph2Seg_phiHits_side = 0;
   ph2Seg_phiHits_wire = 0;
   ph2Seg_phiHits_wirePos = 0;
   ph2Seg_phiHits_layer = 0;
   ph2Seg_phiHits_superLayer = 0;
   ph2Seg_phiHits_time = 0;
   ph2Seg_phiHits_timeCali = 0;
   ph2Seg_z_normChi2 = 0;
   ph2Seg_z_nHits = 0;
   ph2Seg_zHits_pos = 0;
   ph2Seg_zHits_posCh = 0;
   ph2Seg_zHits_posErr = 0;
   ph2Seg_zHits_side = 0;
   ph2Seg_zHits_wire = 0;
   ph2Seg_zHits_wirePos = 0;
   ph2Seg_zHits_layer = 0;
   ph2Seg_zHits_time = 0;
   ph2Seg_zHits_timeCali = 0;
   ph2TpgPhiEmuAm_wheel = 0;
   ph2TpgPhiEmuAm_sector = 0;
   ph2TpgPhiEmuAm_station = 0;
   ph2TpgPhiEmuAm_quality = 0;
   ph2TpgPhiEmuAm_superLayer = 0;
   ph2TpgPhiEmuAm_rpcFlag = 0;
   ph2TpgPhiEmuAm_chi2 = 0;
   ph2TpgPhiEmuAm_phi = 0;
   ph2TpgPhiEmuAm_phiB = 0;
   ph2TpgPhiEmuAm_phiCMSSW = 0;
   ph2TpgPhiEmuAm_phiBCMSSW = 0;
   ph2TpgPhiEmuAm_posLoc_x_raw = 0;
   ph2TpgPhiEmuAm_posLoc_x = 0;
   ph2TpgPhiEmuAm_dirLoc_phi = 0;
   ph2TpgPhiEmuAm_BX = 0;
   ph2TpgPhiEmuAm_t0 = 0;
   ph2TpgPhiEmuAm_index = 0;
   ph2TpgPhiEmuAm_pathWireId = 0;
   ph2TpgPhiEmuAm_pathTDC = 0;
   ph2TpgPhiEmuAm_pathLat = 0;
   ph2TpgThetaEmuAm_wheel = 0;
   ph2TpgThetaEmuAm_sector = 0;
   ph2TpgThetaEmuAm_station = 0;
   ph2TpgThetaEmuAm_quality = 0;
   ph2TpgThetaEmuAm_rpcFlag = 0;
   ph2TpgThetaEmuAm_chi2 = 0;
   ph2TpgThetaEmuAm_z = 0;
   ph2TpgThetaEmuAm_k = 0;
   ph2TpgThetaEmuAm_BX = 0;
   ph2TpgThetaEmuAm_t0 = 0;
   ph2TpgThetaEmuAm_index = 0;
   ph2TpgThetaEmuAm_posLoc_y_raw = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("gen_nGenParts", &gen_nGenParts, &b_gen_nGenParts);
   fChain->SetBranchAddress("gen_pdgId", &gen_pdgId, &b_gen_pdgId);
   fChain->SetBranchAddress("gen_pt", &gen_pt, &b_gen_pt);
   fChain->SetBranchAddress("gen_phi", &gen_phi, &b_gen_phi);
   fChain->SetBranchAddress("gen_eta", &gen_eta, &b_gen_eta);
   fChain->SetBranchAddress("gen_charge", &gen_charge, &b_gen_charge);
   fChain->SetBranchAddress("event_runNumber", &event_runNumber, &b_event_runNumber);
   fChain->SetBranchAddress("event_lumiBlock", &event_lumiBlock, &b_event_lumiBlock);
   fChain->SetBranchAddress("event_eventNumber", &event_eventNumber, &b_event_eventNumber);
   fChain->SetBranchAddress("event_timeStamp", &event_timeStamp, &b_event_timeStamp);
   fChain->SetBranchAddress("event_bunchCrossing", &event_bunchCrossing, &b_event_bunchCrossing);
   fChain->SetBranchAddress("event_orbitNumber", &event_orbitNumber, &b_event_orbitNumber);
   fChain->SetBranchAddress("digi_nDigis", &digi_nDigis, &b_digi_nDigis);
   fChain->SetBranchAddress("digi_wheel", &digi_wheel, &b_digi_wheel);
   fChain->SetBranchAddress("digi_sector", &digi_sector, &b_digi_sector);
   fChain->SetBranchAddress("digi_station", &digi_station, &b_digi_station);
   fChain->SetBranchAddress("digi_superLayer", &digi_superLayer, &b_digi_superLayer);
   fChain->SetBranchAddress("digi_layer", &digi_layer, &b_digi_layer);
   fChain->SetBranchAddress("digi_wire", &digi_wire, &b_digi_wire);
   fChain->SetBranchAddress("digi_time", &digi_time, &b_digi_time);
   fChain->SetBranchAddress("ph2Digi_nDigis", &ph2Digi_nDigis, &b_ph2Digi_nDigis);
   fChain->SetBranchAddress("ph2Digi_wheel", &ph2Digi_wheel, &b_ph2Digi_wheel);
   fChain->SetBranchAddress("ph2Digi_sector", &ph2Digi_sector, &b_ph2Digi_sector);
   fChain->SetBranchAddress("ph2Digi_station", &ph2Digi_station, &b_ph2Digi_station);
   fChain->SetBranchAddress("ph2Digi_superLayer", &ph2Digi_superLayer, &b_ph2Digi_superLayer);
   fChain->SetBranchAddress("ph2Digi_layer", &ph2Digi_layer, &b_ph2Digi_layer);
   fChain->SetBranchAddress("ph2Digi_wire", &ph2Digi_wire, &b_ph2Digi_wire);
   fChain->SetBranchAddress("ph2Digi_time", &ph2Digi_time, &b_ph2Digi_time);
   fChain->SetBranchAddress("seg_nSegments", &seg_nSegments, &b_seg_nSegments);
   fChain->SetBranchAddress("seg_wheel", &seg_wheel, &b_seg_wheel);
   fChain->SetBranchAddress("seg_sector", &seg_sector, &b_seg_sector);
   fChain->SetBranchAddress("seg_station", &seg_station, &b_seg_station);
   fChain->SetBranchAddress("seg_hasPhi", &seg_hasPhi, &b_seg_hasPhi);
   fChain->SetBranchAddress("seg_hasZed", &seg_hasZed, &b_seg_hasZed);
   fChain->SetBranchAddress("seg_posLoc_x", &seg_posLoc_x, &b_seg_posLoc_x);
   fChain->SetBranchAddress("seg_posLoc_y", &seg_posLoc_y, &b_seg_posLoc_y);
   fChain->SetBranchAddress("seg_posLoc_z", &seg_posLoc_z, &b_seg_posLoc_z);
   fChain->SetBranchAddress("seg_dirLoc_x", &seg_dirLoc_x, &b_seg_dirLoc_x);
   fChain->SetBranchAddress("seg_dirLoc_y", &seg_dirLoc_y, &b_seg_dirLoc_y);
   fChain->SetBranchAddress("seg_dirLoc_z", &seg_dirLoc_z, &b_seg_dirLoc_z);
   fChain->SetBranchAddress("seg_posLoc_x_SL1", &seg_posLoc_x_SL1, &b_seg_posLoc_x_SL1);
   fChain->SetBranchAddress("seg_posLoc_x_SL3", &seg_posLoc_x_SL3, &b_seg_posLoc_x_SL3);
   fChain->SetBranchAddress("seg_posLoc_x_midPlane", &seg_posLoc_x_midPlane, &b_seg_posLoc_x_midPlane);
   fChain->SetBranchAddress("seg_posGlb_phi", &seg_posGlb_phi, &b_seg_posGlb_phi);
   fChain->SetBranchAddress("seg_posGlb_phi_midPlane", &seg_posGlb_phi_midPlane, &b_seg_posGlb_phi_midPlane);
   fChain->SetBranchAddress("seg_posGlb_phi_SL1", &seg_posGlb_phi_SL1, &b_seg_posGlb_phi_SL1);
   fChain->SetBranchAddress("seg_posGlb_phi_SL3", &seg_posGlb_phi_SL3, &b_seg_posGlb_phi_SL3);
   fChain->SetBranchAddress("seg_posGlb_eta", &seg_posGlb_eta, &b_seg_posGlb_eta);
   fChain->SetBranchAddress("seg_dirGlb_phi", &seg_dirGlb_phi, &b_seg_dirGlb_phi);
   fChain->SetBranchAddress("seg_dirGlb_eta", &seg_dirGlb_eta, &b_seg_dirGlb_eta);
   fChain->SetBranchAddress("seg_hitsExpPos", &seg_hitsExpPos, &b_seg_hitsExpPos);
   fChain->SetBranchAddress("seg_hitsExpPosCh", &seg_hitsExpPosCh, &b_seg_hitsExpPosCh);
   fChain->SetBranchAddress("seg_hitsExpWire", &seg_hitsExpWire, &b_seg_hitsExpWire);
   fChain->SetBranchAddress("seg_phi_t0", &seg_phi_t0, &b_seg_phi_t0);
   fChain->SetBranchAddress("seg_phi_vDrift", &seg_phi_vDrift, &b_seg_phi_vDrift);
   fChain->SetBranchAddress("seg_phi_normChi2", &seg_phi_normChi2, &b_seg_phi_normChi2);
   fChain->SetBranchAddress("seg_phi_nHits", &seg_phi_nHits, &b_seg_phi_nHits);
   fChain->SetBranchAddress("seg_phiHits_pos", &seg_phiHits_pos, &b_seg_phiHits_pos);
   fChain->SetBranchAddress("seg_phiHits_posCh", &seg_phiHits_posCh, &b_seg_phiHits_posCh);
   fChain->SetBranchAddress("seg_phiHits_posErr", &seg_phiHits_posErr, &b_seg_phiHits_posErr);
   fChain->SetBranchAddress("seg_phiHits_side", &seg_phiHits_side, &b_seg_phiHits_side);
   fChain->SetBranchAddress("seg_phiHits_wire", &seg_phiHits_wire, &b_seg_phiHits_wire);
   fChain->SetBranchAddress("seg_phiHits_wirePos", &seg_phiHits_wirePos, &b_seg_phiHits_wirePos);
   fChain->SetBranchAddress("seg_phiHits_layer", &seg_phiHits_layer, &b_seg_phiHits_layer);
   fChain->SetBranchAddress("seg_phiHits_superLayer", &seg_phiHits_superLayer, &b_seg_phiHits_superLayer);
   fChain->SetBranchAddress("seg_phiHits_time", &seg_phiHits_time, &b_seg_phiHits_time);
   fChain->SetBranchAddress("seg_phiHits_timeCali", &seg_phiHits_timeCali, &b_seg_phiHits_timeCali);
   fChain->SetBranchAddress("seg_z_normChi2", &seg_z_normChi2, &b_seg_z_normChi2);
   fChain->SetBranchAddress("seg_z_nHits", &seg_z_nHits, &b_seg_z_nHits);
   fChain->SetBranchAddress("seg_zHits_pos", &seg_zHits_pos, &b_seg_zHits_pos);
   fChain->SetBranchAddress("seg_zHits_posCh", &seg_zHits_posCh, &b_seg_zHits_posCh);
   fChain->SetBranchAddress("seg_zHits_posErr", &seg_zHits_posErr, &b_seg_zHits_posErr);
   fChain->SetBranchAddress("seg_zHits_side", &seg_zHits_side, &b_seg_zHits_side);
   fChain->SetBranchAddress("seg_zHits_wire", &seg_zHits_wire, &b_seg_zHits_wire);
   fChain->SetBranchAddress("seg_zHits_wirePos", &seg_zHits_wirePos, &b_seg_zHits_wirePos);
   fChain->SetBranchAddress("seg_zHits_layer", &seg_zHits_layer, &b_seg_zHits_layer);
   fChain->SetBranchAddress("seg_zHits_time", &seg_zHits_time, &b_seg_zHits_time);
   fChain->SetBranchAddress("seg_zHits_timeCali", &seg_zHits_timeCali, &b_seg_zHits_timeCali);
   fChain->SetBranchAddress("ph2Seg_nSegments", &ph2Seg_nSegments, &b_ph2Seg_nSegments);
   fChain->SetBranchAddress("ph2Seg_wheel", &ph2Seg_wheel, &b_ph2Seg_wheel);
   fChain->SetBranchAddress("ph2Seg_sector", &ph2Seg_sector, &b_ph2Seg_sector);
   fChain->SetBranchAddress("ph2Seg_station", &ph2Seg_station, &b_ph2Seg_station);
   fChain->SetBranchAddress("ph2Seg_hasPhi", &ph2Seg_hasPhi, &b_ph2Seg_hasPhi);
   fChain->SetBranchAddress("ph2Seg_hasZed", &ph2Seg_hasZed, &b_ph2Seg_hasZed);
   fChain->SetBranchAddress("ph2Seg_posLoc_x", &ph2Seg_posLoc_x, &b_ph2Seg_posLoc_x);
   fChain->SetBranchAddress("ph2Seg_posLoc_y", &ph2Seg_posLoc_y, &b_ph2Seg_posLoc_y);
   fChain->SetBranchAddress("ph2Seg_posLoc_z", &ph2Seg_posLoc_z, &b_ph2Seg_posLoc_z);
   fChain->SetBranchAddress("ph2Seg_dirLoc_x", &ph2Seg_dirLoc_x, &b_ph2Seg_dirLoc_x);
   fChain->SetBranchAddress("ph2Seg_dirLoc_y", &ph2Seg_dirLoc_y, &b_ph2Seg_dirLoc_y);
   fChain->SetBranchAddress("ph2Seg_dirLoc_z", &ph2Seg_dirLoc_z, &b_ph2Seg_dirLoc_z);
   fChain->SetBranchAddress("ph2Seg_posLoc_x_SL1", &ph2Seg_posLoc_x_SL1, &b_ph2Seg_posLoc_x_SL1);
   fChain->SetBranchAddress("ph2Seg_posLoc_x_SL3", &ph2Seg_posLoc_x_SL3, &b_ph2Seg_posLoc_x_SL3);
   fChain->SetBranchAddress("ph2Seg_posLoc_x_midPlane", &ph2Seg_posLoc_x_midPlane, &b_ph2Seg_posLoc_x_midPlane);
   fChain->SetBranchAddress("ph2Seg_posGlb_phi", &ph2Seg_posGlb_phi, &b_ph2Seg_posGlb_phi);
   fChain->SetBranchAddress("ph2Seg_posGlb_phi_midPlane", &ph2Seg_posGlb_phi_midPlane, &b_ph2Seg_posGlb_phi_midPlane);
   fChain->SetBranchAddress("ph2Seg_posGlb_phi_SL1", &ph2Seg_posGlb_phi_SL1, &b_ph2Seg_posGlb_phi_SL1);
   fChain->SetBranchAddress("ph2Seg_posGlb_phi_SL3", &ph2Seg_posGlb_phi_SL3, &b_ph2Seg_posGlb_phi_SL3);
   fChain->SetBranchAddress("ph2Seg_posGlb_eta", &ph2Seg_posGlb_eta, &b_ph2Seg_posGlb_eta);
   fChain->SetBranchAddress("ph2Seg_dirGlb_phi", &ph2Seg_dirGlb_phi, &b_ph2Seg_dirGlb_phi);
   fChain->SetBranchAddress("ph2Seg_dirGlb_eta", &ph2Seg_dirGlb_eta, &b_ph2Seg_dirGlb_eta);
   fChain->SetBranchAddress("ph2Seg_hitsExpPos", &ph2Seg_hitsExpPos, &b_ph2Seg_hitsExpPos);
   fChain->SetBranchAddress("ph2Seg_hitsExpPosCh", &ph2Seg_hitsExpPosCh, &b_ph2Seg_hitsExpPosCh);
   fChain->SetBranchAddress("ph2Seg_hitsExpWire", &ph2Seg_hitsExpWire, &b_ph2Seg_hitsExpWire);
   fChain->SetBranchAddress("ph2Seg_phi_t0", &ph2Seg_phi_t0, &b_ph2Seg_phi_t0);
   fChain->SetBranchAddress("ph2Seg_phi_vDrift", &ph2Seg_phi_vDrift, &b_ph2Seg_phi_vDrift);
   fChain->SetBranchAddress("ph2Seg_phi_normChi2", &ph2Seg_phi_normChi2, &b_ph2Seg_phi_normChi2);
   fChain->SetBranchAddress("ph2Seg_phi_nHits", &ph2Seg_phi_nHits, &b_ph2Seg_phi_nHits);
   fChain->SetBranchAddress("ph2Seg_phiHits_pos", &ph2Seg_phiHits_pos, &b_ph2Seg_phiHits_pos);
   fChain->SetBranchAddress("ph2Seg_phiHits_posCh", &ph2Seg_phiHits_posCh, &b_ph2Seg_phiHits_posCh);
   fChain->SetBranchAddress("ph2Seg_phiHits_posErr", &ph2Seg_phiHits_posErr, &b_ph2Seg_phiHits_posErr);
   fChain->SetBranchAddress("ph2Seg_phiHits_side", &ph2Seg_phiHits_side, &b_ph2Seg_phiHits_side);
   fChain->SetBranchAddress("ph2Seg_phiHits_wire", &ph2Seg_phiHits_wire, &b_ph2Seg_phiHits_wire);
   fChain->SetBranchAddress("ph2Seg_phiHits_wirePos", &ph2Seg_phiHits_wirePos, &b_ph2Seg_phiHits_wirePos);
   fChain->SetBranchAddress("ph2Seg_phiHits_layer", &ph2Seg_phiHits_layer, &b_ph2Seg_phiHits_layer);
   fChain->SetBranchAddress("ph2Seg_phiHits_superLayer", &ph2Seg_phiHits_superLayer, &b_ph2Seg_phiHits_superLayer);
   fChain->SetBranchAddress("ph2Seg_phiHits_time", &ph2Seg_phiHits_time, &b_ph2Seg_phiHits_time);
   fChain->SetBranchAddress("ph2Seg_phiHits_timeCali", &ph2Seg_phiHits_timeCali, &b_ph2Seg_phiHits_timeCali);
   fChain->SetBranchAddress("ph2Seg_z_normChi2", &ph2Seg_z_normChi2, &b_ph2Seg_z_normChi2);
   fChain->SetBranchAddress("ph2Seg_z_nHits", &ph2Seg_z_nHits, &b_ph2Seg_z_nHits);
   fChain->SetBranchAddress("ph2Seg_zHits_pos", &ph2Seg_zHits_pos, &b_ph2Seg_zHits_pos);
   fChain->SetBranchAddress("ph2Seg_zHits_posCh", &ph2Seg_zHits_posCh, &b_ph2Seg_zHits_posCh);
   fChain->SetBranchAddress("ph2Seg_zHits_posErr", &ph2Seg_zHits_posErr, &b_ph2Seg_zHits_posErr);
   fChain->SetBranchAddress("ph2Seg_zHits_side", &ph2Seg_zHits_side, &b_ph2Seg_zHits_side);
   fChain->SetBranchAddress("ph2Seg_zHits_wire", &ph2Seg_zHits_wire, &b_ph2Seg_zHits_wire);
   fChain->SetBranchAddress("ph2Seg_zHits_wirePos", &ph2Seg_zHits_wirePos, &b_ph2Seg_zHits_wirePos);
   fChain->SetBranchAddress("ph2Seg_zHits_layer", &ph2Seg_zHits_layer, &b_ph2Seg_zHits_layer);
   fChain->SetBranchAddress("ph2Seg_zHits_time", &ph2Seg_zHits_time, &b_ph2Seg_zHits_time);
   fChain->SetBranchAddress("ph2Seg_zHits_timeCali", &ph2Seg_zHits_timeCali, &b_ph2Seg_zHits_timeCali);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_nTrigs", &ph2TpgPhiEmuAm_nTrigs, &b_ph2TpgPhiEmuAm_nTrigs);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_wheel", &ph2TpgPhiEmuAm_wheel, &b_ph2TpgPhiEmuAm_wheel);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_sector", &ph2TpgPhiEmuAm_sector, &b_ph2TpgPhiEmuAm_sector);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_station", &ph2TpgPhiEmuAm_station, &b_ph2TpgPhiEmuAm_station);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_quality", &ph2TpgPhiEmuAm_quality, &b_ph2TpgPhiEmuAm_quality);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_superLayer", &ph2TpgPhiEmuAm_superLayer, &b_ph2TpgPhiEmuAm_superLayer);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_rpcFlag", &ph2TpgPhiEmuAm_rpcFlag, &b_ph2TpgPhiEmuAm_rpcFlag);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_chi2", &ph2TpgPhiEmuAm_chi2, &b_ph2TpgPhiEmuAm_chi2);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_phi", &ph2TpgPhiEmuAm_phi, &b_ph2TpgPhiEmuAm_phi);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_phiB", &ph2TpgPhiEmuAm_phiB, &b_ph2TpgPhiEmuAm_phiB);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_phiCMSSW", &ph2TpgPhiEmuAm_phiCMSSW, &b_ph2TpgPhiEmuAm_phiCMSSW);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_phiBCMSSW", &ph2TpgPhiEmuAm_phiBCMSSW, &b_ph2TpgPhiEmuAm_phiBCMSSW);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_posLoc_x_raw", &ph2TpgPhiEmuAm_posLoc_x_raw, &b_ph2TpgPhiEmuAm_posLoc_x_raw);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_posLoc_x", &ph2TpgPhiEmuAm_posLoc_x, &b_ph2TpgPhiEmuAm_posLoc_x);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_dirLoc_phi", &ph2TpgPhiEmuAm_dirLoc_phi, &b_ph2TpgPhiEmuAm_dirLoc_phi);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_BX", &ph2TpgPhiEmuAm_BX, &b_ph2TpgPhiEmuAm_BX);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_t0", &ph2TpgPhiEmuAm_t0, &b_ph2TpgPhiEmuAm_t0);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_index", &ph2TpgPhiEmuAm_index, &b_ph2TpgPhiEmuAm_index);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_pathWireId", &ph2TpgPhiEmuAm_pathWireId, &b_ph2TpgPhiEmuAm_pathWireId);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_pathTDC", &ph2TpgPhiEmuAm_pathTDC, &b_ph2TpgPhiEmuAm_pathTDC);
   fChain->SetBranchAddress("ph2TpgPhiEmuAm_pathLat", &ph2TpgPhiEmuAm_pathLat, &b_ph2TpgPhiEmuAm_pathLat);
   fChain->SetBranchAddress("ph2TpgThetaEmuAm_nTrigs", &ph2TpgThetaEmuAm_nTrigs, &b_ph2TpgThetaEmuAm_nTrigs);
   fChain->SetBranchAddress("ph2TpgThetaEmuAm_wheel", &ph2TpgThetaEmuAm_wheel, &b_ph2TpgThetaEmuAm_wheel);
   fChain->SetBranchAddress("ph2TpgThetaEmuAm_sector", &ph2TpgThetaEmuAm_sector, &b_ph2TpgThetaEmuAm_sector);
   fChain->SetBranchAddress("ph2TpgThetaEmuAm_station", &ph2TpgThetaEmuAm_station, &b_ph2TpgThetaEmuAm_station);
   fChain->SetBranchAddress("ph2TpgThetaEmuAm_quality", &ph2TpgThetaEmuAm_quality, &b_ph2TpgThetaEmuAm_quality);
   fChain->SetBranchAddress("ph2TpgThetaEmuAm_rpcFlag", &ph2TpgThetaEmuAm_rpcFlag, &b_ph2TpgThetaEmuAm_rpcFlag);
   fChain->SetBranchAddress("ph2TpgThetaEmuAm_chi2", &ph2TpgThetaEmuAm_chi2, &b_ph2TpgThetaEmuAm_chi2);
   fChain->SetBranchAddress("ph2TpgThetaEmuAm_z", &ph2TpgThetaEmuAm_z, &b_ph2TpgThetaEmuAm_z);
   fChain->SetBranchAddress("ph2TpgThetaEmuAm_k", &ph2TpgThetaEmuAm_k, &b_ph2TpgThetaEmuAm_k);
   fChain->SetBranchAddress("ph2TpgThetaEmuAm_BX", &ph2TpgThetaEmuAm_BX, &b_ph2TpgThetaEmuAm_BX);
   fChain->SetBranchAddress("ph2TpgThetaEmuAm_t0", &ph2TpgThetaEmuAm_t0, &b_ph2TpgThetaEmuAm_t0);
   fChain->SetBranchAddress("ph2TpgThetaEmuAm_index", &ph2TpgThetaEmuAm_index, &b_ph2TpgThetaEmuAm_index);
   fChain->SetBranchAddress("ph2TpgThetaEmuAm_posLoc_y_raw", &ph2TpgThetaEmuAm_posLoc_y_raw, &b_ph2TpgThetaEmuAm_posLoc_y_raw);
   Notify();
}

Bool_t DTTREEgun::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DTTREEgun::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DTTREEgun::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
Int_t DTTREEgun::BestSeg(Int_t index, Int_t iStationToLook){

Float_t eta = gen_eta->at(index);
Float_t phi = gen_phi->at(index);
Int_t nhits = 0;
Float_t cutEta = 0.15;
Int_t iBestSeg = -1;

for (uint i = 0; i < seg_nSegments ; ++i){
 if(seg_station->at(i)!=iStationToLook) continue;
 if(fabs(phi-seg_posGlb_phi->at(i))>0.2) continue;
// if(seg_hasZed->at(i)!=1) cutEta = 0.3;
 if(seg_hasZed->at(i)!=1) continue;
 if(fabs(eta-seg_posGlb_eta->at(i))>cutEta) continue;
 if(seg_phi_nHits->at(i)>nhits) {nhits = seg_phi_nHits->at(i);
       iBestSeg=i;
 }
}
return iBestSeg;
}


Int_t DTTREEgun::BestTrig(Int_t index, Int_t iStationToLook, Int_t wheel, Int_t trigQual){
Float_t minDist = 9999999999.;
Float_t xpos = seg_posLoc_x->at(index);
Int_t iBestTrig = -1;

for (uint i = 0; i < ph2TpgPhiEmuAm_nTrigs; ++i){
 if(ph2TpgPhiEmuAm_station->at(i)!=iStationToLook) continue;
 if(ph2TpgPhiEmuAm_wheel->at(i)!=wheel) continue;
 if(ph2TpgPhiEmuAm_quality->at(i)<trigQual) continue;
 if( fabs(xpos -ph2TpgPhiEmuAm_posLoc_x->at(i))<minDist){
  iBestTrig=i;
  minDist=fabs(xpos -ph2TpgPhiEmuAm_posLoc_x->at(i));
//  if(minDist<1) cout<<"minDistX: "<<minDist<<endl;
}
}
return iBestTrig;
}

Int_t DTTREEgun::BestTrigZ(Int_t index, Int_t iStationToLook, Int_t wheel, Int_t trigQual){
Float_t minDist = 9999999999.;
Float_t ypos = (-seg_posLoc_y->at(index)+120)*1000;
Int_t iBestTrigZ = -1;

for (uint i = 0; i < ph2TpgThetaEmuAm_nTrigs; ++i){
 if(ph2TpgThetaEmuAm_station->at(i)!=iStationToLook) continue;
 if(ph2TpgThetaEmuAm_wheel->at(i)!=wheel) continue;
 if(ph2TpgThetaEmuAm_quality->at(i)<trigQual) continue;
 if( fabs(ypos-ph2TpgThetaEmuAm_posLoc_y_raw->at(i))<minDist){
  iBestTrigZ=i;
  minDist=fabs(ypos -ph2TpgThetaEmuAm_posLoc_y_raw->at(i));
//  if(minDist/1000<5) cout<<"minDistY: "<<minDist<<endl;
}
}
//if(minDist/1000>5) iBestTrigZ = -1;

return iBestTrigZ;
}


#endif // #ifdef DTTREEgun_cxx
