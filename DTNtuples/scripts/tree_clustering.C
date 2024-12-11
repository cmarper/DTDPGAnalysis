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

void make_tree(TString filename, int maxevents = -1, unsigned int minsize = 2, TString suffix="_clustered"){

  //minsize is minimum cluster size in number of strips
  
  TChain * tree = new TChain("dtNtupleProducer/DTTREE");
  tree->Add(filename);

  //Create a new file and clone the old tree

  TString newfilename = filename.ReplaceAll(".root","")+suffix+TString(".root");
  TFile * newfile = TFile::Open(newfilename.Data(),"recreate");

  TTree * newtree = tree->CloneTree(0);

  // Get old branches to use for clustering

  vector<int> *rpcDigi_region = nullptr; 
  vector<int> *rpcDigi_wheel = nullptr; 
  vector<int> *rpcDigi_sector = nullptr;  
  vector<int> *rpcDigi_subsector = nullptr; 
  vector<int> *rpcDigi_station = nullptr; 
  vector<int> *rpcDigi_layer = nullptr; 
  vector<int> *rpcDigi_stla = nullptr; 
  vector<int> *rpcDigi_roll = nullptr; 
  vector<int> *rpcDigi_BX = nullptr; 
  vector<int> *rpcDigi_time = nullptr; 
  vector<int> *rpcDigi_strip = nullptr; 

  tree->SetBranchAddress("rpcDigi_region", &rpcDigi_region);
  tree->SetBranchAddress("rpcDigi_wheel", &rpcDigi_wheel);
  tree->SetBranchAddress("rpcDigi_sector", &rpcDigi_sector);
  tree->SetBranchAddress("rpcDigi_subsector", &rpcDigi_subsector);
  tree->SetBranchAddress("rpcDigi_station", &rpcDigi_station);
  tree->SetBranchAddress("rpcDigi_layer", &rpcDigi_layer);
  tree->SetBranchAddress("rpcDigi_stla", &rpcDigi_stla);
  tree->SetBranchAddress("rpcDigi_roll", &rpcDigi_roll);
  tree->SetBranchAddress("rpcDigi_BX", &rpcDigi_BX);
  tree->SetBranchAddress("rpcDigi_time", &rpcDigi_time);
  tree->SetBranchAddress("rpcDigi_strip", &rpcDigi_strip);

  // Add new cluster branches 

  vector<float> rpcCluster_nStrips;
  vector<int> rpcCluster_region;
  vector<int> rpcCluster_wheel;
  vector<int> rpcCluster_sector;
  vector<int> rpcCluster_subsector;
  vector<int> rpcCluster_station;
  vector<int> rpcCluster_layer;
  vector<int> rpcCluster_stla;
  vector<int> rpcCluster_roll;
  vector<int> rpcCluster_BX;
  vector<int> rpcCluster_time;
  vector<float> rpcCluster_avgstrip;

  newtree->Branch("rpcCluster_nStrips", &rpcCluster_nStrips);
  newtree->Branch("rpcCluster_region", &rpcCluster_region);
  newtree->Branch("rpcCluster_wheel", &rpcCluster_wheel);
  newtree->Branch("rpcCluster_sector", &rpcCluster_sector);
  newtree->Branch("rpcCluster_subsector", &rpcCluster_subsector);
  newtree->Branch("rpcCluster_station", &rpcCluster_station);
  newtree->Branch("rpcCluster_layer", &rpcCluster_layer);
  newtree->Branch("rpcCluster_stla", &rpcCluster_stla);
  newtree->Branch("rpcCluster_roll", &rpcCluster_roll);
  newtree->Branch("rpcCluster_BX", &rpcCluster_BX);
  newtree->Branch("rpcCluster_time",&rpcCluster_time);
  newtree->Branch("rpcCluster_avgstrip", &rpcCluster_avgstrip);

  // Loop over events

  Long64_t nEntries = tree->GetEntries();

  if((maxevents<nEntries) && (maxevents!=-1)) nEntries = maxevents;
  
  for (Long64_t i = 0; i < nEntries; ++i) {

    if(i%1000==0) cout<<" i = "<<i<<endl;

    tree->GetEntry(i);

    map<tuple<int,int,int,int,int,int,int,int,int>, DigiData> groupedData;

    size_t nDigis = (*rpcDigi_wheel).size();

    rpcCluster_nStrips.clear();
    rpcCluster_region.clear();
    rpcCluster_wheel.clear();
    rpcCluster_sector.clear();
    rpcCluster_subsector.clear();
    rpcCluster_station.clear();
    rpcCluster_layer.clear();
    rpcCluster_stla.clear();
    rpcCluster_roll.clear();
    rpcCluster_BX.clear();
    rpcCluster_time.clear();
    rpcCluster_avgstrip.clear();

    for (size_t j = 0; j < nDigis; ++j) {

        int region = (*rpcDigi_region).at(j);
        int wheel = (*rpcDigi_wheel).at(j);
        int sector = (*rpcDigi_sector).at(j);
        int subsector = (*rpcDigi_subsector).at(j);
        int station = (*rpcDigi_station).at(j);
        int layer = (*rpcDigi_layer).at(j);
        int stla = (*rpcDigi_stla).at(j);
        int roll = (*rpcDigi_roll).at(j);
        int bx = (*rpcDigi_BX).at(j);
        int time = (*rpcDigi_time).at(j);
        int strip = (*rpcDigi_strip).at(j);

        // Create a tuple to represent the grouping key
        tuple<int,int,int,int,int,int,int,int,int> key = make_tuple(region, wheel, sector, subsector, station, layer, stla, roll, bx);

        // Group the data using the key
        groupedData[key].regions.push_back(region);
        groupedData[key].wheels.push_back(wheel);
        groupedData[key].sectors.push_back(sector);
        groupedData[key].subsectors.push_back(subsector);
        groupedData[key].stations.push_back(station);
        groupedData[key].layers.push_back(layer);
        groupedData[key].stlas.push_back(stla);
        groupedData[key].rolls.push_back(roll);
        groupedData[key].bxs.push_back(bx);
        groupedData[key].times.push_back(time);
        groupedData[key].strips.push_back(strip);
    }

    int nclusters_tot = 0;

    // Build the clusters
    for (const auto& entry : groupedData) {

        const auto& key = entry.first;
        const auto& data = entry.second;

        int region = get<0>(key);
        int wheel = get<1>(key);
        int sector = get<2>(key);
        int subsector = get<3>(key);
        int station = get<4>(key);
        int layer = get<5>(key);
        int stla = get<6>(key);
        int roll = get<7>(key);
        int bx = get<8>(key);
        int time = data.times[0];

        if(data.wheels.size()<minsize) continue;

        vector<vector<int>> clusters = grouping(data.strips);

        // Loop over clusters

        for (const auto& cluster : clusters) {

            float sum_strips = 0;
            float n_strips = 0;

            // Loop over strips in cluster and get global variables

            for (int stripn : cluster) {
                n_strips++;
                sum_strips += stripn;
            }
            float avrg_strip = sum_strips/n_strips;

            // Fill in the cluster variables

            if(n_strips<minsize) continue;

            nclusters_tot++;

            rpcCluster_nStrips.push_back(n_strips);
            rpcCluster_region.push_back(region);
            rpcCluster_wheel.push_back(wheel);
            rpcCluster_sector.push_back(sector);
            rpcCluster_subsector.push_back(subsector);
            rpcCluster_station.push_back(station);
            rpcCluster_layer.push_back(layer);
            rpcCluster_stla.push_back(stla);
            rpcCluster_roll.push_back(roll);
            rpcCluster_avgstrip.push_back(avrg_strip);
            rpcCluster_BX.push_back(bx);
            rpcCluster_time.push_back(time);

        }
         
    }

    newtree->Fill();

  }

  // Flush to disk
  newfile->Write();
  newfile->Close();

  return;

}
