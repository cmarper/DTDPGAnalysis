// C. Martin Perez, CIEMAT, 2024
// Script to skim ntuples for neural network inputs

#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TString.h>

#include <iostream>

using namespace std;

// Methods for clusters
struct DigiData {
    vector<int> regions;
    vector<int> wheels;
    vector<int> sectors;
    vector<int> subsectors;
    vector<int> stations;
    vector<int> layers;
    vector<int> stlas;
    vector<int> rolls;
    vector<int> bxs;
    vector<int> times;
    vector<int> strips;
};

// CLustering function
vector<vector<int>> grouping(const vector<int>& stripsinput) {

    vector<vector<int>> grouped;

    vector<int> input = stripsinput;

    if (input.empty()) return grouped;

    sort(input.begin(), input.end());

    vector<int> currentGroup;
    currentGroup.push_back(input[0]);

    // Iterate through the vector and group contiguous elements
    for (size_t i = 1; i < input.size(); ++i) {
        // Check if the current element is contiguous with the previous one
        if (input[i] == input[i - 1] + 1) {
            currentGroup.push_back(input[i]);
        } else {
            // If not contiguous, save the current group and start a new one
            grouped.push_back(currentGroup);
            currentGroup.clear();
            currentGroup.push_back(input[i]);
        }
    }

    // Add the last group
    grouped.push_back(currentGroup);

    return grouped;
}

void make_tree(TString filename, TString suffix="_skimmed"){
  
  TChain * tree = new TChain("DTTREE");
  tree->Add(filename);

  // Deactivate all branches

  tree->SetBranchStatus("*",0);

  // Activate the necessary branches

  tree->SetBranchStatus("gen_nGenParts",1);
  tree->SetBranchStatus("gen_pdgId",1);
  tree->SetBranchStatus("gen_pt",1);
  tree->SetBranchStatus("gen_phi",1);
  tree->SetBranchStatus("gen_eta",1);
  tree->SetBranchStatus("gen_charge",1);

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

  tree->SetBranchStatus("ph2TpgPhiEmuAm_wheel",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_sector",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_station",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_quality",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_superLayer",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_rpcFlag",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_phi",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_phiB",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_phiCMSSW",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_phiBCMSSW",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_BX",1);
  tree->SetBranchStatus("ph2TpgPhiEmuAm_t0",1);

  tree->SetBranchStatus("rpcDigi_nDigis",1);
  tree->SetBranchStatus("rpcDigi_region",1);
  tree->SetBranchStatus("rpcDigi_wheel",1);
  tree->SetBranchStatus("rpcDigi_sector",1);
  tree->SetBranchStatus("rpcDigi_subsector",1);
  tree->SetBranchStatus("rpcDigi_station",1);
  tree->SetBranchStatus("rpcDigi_layer",1);
  tree->SetBranchStatus("rpcDigi_stla",1);
  tree->SetBranchStatus("rpcDigi_roll",1);
  tree->SetBranchStatus("rpcDigi_strip",1);
  tree->SetBranchStatus("rpcDigi_BX",1);
  tree->SetBranchStatus("rpcDigi_time",1);

  tree->SetBranchStatus("rpcCluster_nStrips",1);
  tree->SetBranchStatus("rpcCluster_region",1);
  tree->SetBranchStatus("rpcCluster_wheel",1);
  tree->SetBranchStatus("rpcCluster_sector",1);
  tree->SetBranchStatus("rpcCluster_subsector",1);
  tree->SetBranchStatus("rpcCluster_station",1);
  tree->SetBranchStatus("rpcCluster_layer",1);
  tree->SetBranchStatus("rpcCluster_stla",1);
  tree->SetBranchStatus("rpcCluster_roll",1);
  tree->SetBranchStatus("rpcCluster_BX",1);
  tree->SetBranchStatus("rpcCluster_time",1);
  tree->SetBranchStatus("rpcCluster_avgstrip",1);

  //Create a new file and clone the old tree header

  TString newfilename = filename.ReplaceAll(".root","")+suffix+TString(".root");
  TFile * newfile = TFile::Open(newfilename.Data(),"recreate");

  TTree * newtree = tree->CloneTree(0);

  // Copy the old branches over

  newtree->CopyEntries(tree);

  // Flush to disk
  newfile->Write();
  newfile->Close();

  return;

}
