// C. Martin Perez, CIEMAT, 2024
// Script to skim ntuples for neural network inputs

#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TString.h>

#include <iostream>

using namespace std;

void make_tree(TString filename, bool ageing = 0, int coin = 0, int quality = 0, TString suffix="_skimmed"){
  
  TChain * tree = new TChain("dtNtupleProducer/DTTREE");
  tree->Add(filename);
  
  Long64_t nentries = tree->GetEntries();
  cout<<", nentries="<<tree->GetEntries()<<endl;

  // Deactivate all branches

  tree->SetBranchStatus("*",0);

  // Activate the necessary branches

  tree->SetBranchStatus("ph2TpgPhiEmuAm_wheel",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_sector",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_station",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_quality",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_superLayer",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_rpcFlag",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_phi",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_phiB",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_BX",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_t0",1);

  tree->SetBranchStatus("seg_nSegments",1);
  tree->SetBranchStatus("seg_wheel",1);
  tree->SetBranchStatus("seg_sector",1);
  tree->SetBranchStatus("seg_station",1);
  tree->SetBranchStatus("seg_posGlb_phi",1);
  tree->SetBranchStatus("seg_posGlb_eta",1);
  tree->SetBranchStatus("seg_dirGlb_phi",1);
  tree->SetBranchStatus("seg_dirGlb_eta",1);
  tree->SetBranchStatus("seg_phi_nHits",1);
  tree->SetBranchStatus("seg_phi_t0",1);
  tree->SetBranchStatus("seg_z_nHits",1);

  tree->SetBranchStatus("rpcDigi_nDigis",1);
  tree->SetBranchStatus("rpcDigi_region",1);
  tree->SetBranchStatus("rpcDigi_sector",1);
  tree->SetBranchStatus("rpcDigi_station",1);
  tree->SetBranchStatus("rpcDigi_strip",1);
  tree->SetBranchStatus("rpcDigi_BX",1);
  tree->SetBranchStatus("rpcDigi_time",1);
  tree->SetBranchStatus("rpcDigi_coordinateX",1);
  tree->SetBranchStatus("rpcDigi_coordinateY",1);

  //Create a new file and clone the old tree header

  TString newfilename = filename.ReplaceAll(".root","")+suffix+TString(".root");
  TFile * newfile = TFile::Open(newfilename.Data(),"recreate");

  TTree * newtree = tree->CloneTree(0);

  // Copy the branches over

  newtree->CopyEntries(tree);

  // Add the new branches 

  newtree->Branch("ageing", &ageing, "ageing/O");
  newtree->Branch("coincidence_flag", &coin, "coin/I");
  newtree->Branch("coincidence_quality", &quality, "quality/I");

  // Flush to disk

  newfile->Write();
  newfile->Close();
  newfile->Delete();
  tree->Delete();  

  return;

}
