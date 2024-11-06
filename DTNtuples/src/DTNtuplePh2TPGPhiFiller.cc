/** \class DTNtuplePh2TPGPhiFiller DTNtuplePh2TPGPhiFiller.cc DTDPGAnalysis/DTNtuples/src/DTNtuplePh2TPGPhiFiller.cc
 *  
 * Helper class : the Phase-1 local trigger filler for TwinMux in/out and BMTF in (the DataFormat is the same)
 *
 * \author C. Battilana (INFN BO)
 *
 *
 */

#include "DTDPGAnalysis/DTNtuples/src/DTNtuplePh2TPGPhiFiller.h"

#include "FWCore/Framework/interface/Event.h"
//#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include <iostream>
using namespace cmsdt;
using namespace std;

DTNtuplePh2TPGPhiFiller::DTNtuplePh2TPGPhiFiller(edm::ConsumesCollector && collector,
					   const std::shared_ptr<DTNtupleConfig> config, 
					   std::shared_ptr<TTree> tree, const std::string & label,
					   TriggerTag tag) : 
  DTNtupleBaseFiller(config, tree, label), m_tag(tag)
{

  edm::InputTag iTag;

  switch (m_tag)
    {
    case TriggerTag::HW :
      iTag = m_config->m_inputTags["ph2TPGPhiHwTag"];
      break;
    case TriggerTag::HB :
      iTag = m_config->m_inputTags["ph2TPGPhiEmuHbTag"];
      break;
    case TriggerTag::AM :
      iTag = m_config->m_inputTags["ph2TPGPhiEmuAmTag"];
    }
  if (iTag.label() != "none") {
    if (!m_config->m_boolParams["useExtDataformat"]) m_dtTriggerToken = collector.consumes<L1Phase2MuDTPhContainer>(iTag);
    else m_dtTriggerTokenExt = collector.consumes<L1Phase2MuDTExtPhContainer>(iTag);
  }

  int rawId;
  shift_filename_ = edm::FileInPath(m_config->m_stringParams["shift_filename"]);
  std::ifstream ifin3(shift_filename_.fullPath());
  double shift;
  if (ifin3.fail()) {
    throw cms::Exception("Missing Input File")
        << "DTNtuplePh2TPGPhiFiller::DTNtuplePh2TPGPhiFiller() -  Cannot find " << shift_filename_.fullPath();
  }
  while (ifin3.good()) {
    ifin3 >> rawId >> shift;
    shiftinfo_[rawId] = shift;
  }

  int wh, st, se, maxdrift;
  maxdrift_filename_ = edm::FileInPath(m_config->m_stringParams["maxdrift_filename"]);
  std::ifstream ifind(maxdrift_filename_.fullPath());
  if (ifind.fail()) {
    throw cms::Exception("Missing Input File")
        << "DTNtuplePh2TPGPhiFiller::DTNtuplePh2TPGPhiFiller() -  Cannot find " << maxdrift_filename_.fullPath();
  }
  while (ifind.good()) {
    ifind >> wh >> st >> se >> maxdrift;
    maxdriftinfo_[wh][st][se] = maxdrift;
  }
}

DTNtuplePh2TPGPhiFiller::~DTNtuplePh2TPGPhiFiller() 
{ 

};

void DTNtuplePh2TPGPhiFiller::initialize()
{
  
  m_tree->Branch((m_label + "_nTrigs").c_str(), &m_nTrigs, (m_label + "_nTrigs/i").c_str());
  
  m_tree->Branch((m_label + "_wheel").c_str(),   &m_lt_wheel);
  m_tree->Branch((m_label + "_sector").c_str(),  &m_lt_sector);
  m_tree->Branch((m_label + "_station").c_str(), &m_lt_station);

  m_tree->Branch((m_label + "_quality").c_str(), &m_lt_quality);
  m_tree->Branch((m_label + "_superLayer").c_str(), &m_lt_superLayer);

  m_tree->Branch((m_label + "_rpcFlag").c_str(), &m_lt_rpcFlag);
  m_tree->Branch((m_label + "_chi2").c_str(),    &m_lt_chi2);

  m_tree->Branch((m_label + "_phi").c_str(),  &m_lt_phi);
  m_tree->Branch((m_label + "_phiB").c_str(), &m_lt_phiB);

  m_tree->Branch((m_label + "_phiCMSSW").c_str(),  &m_lt_phiCMSSW);
  m_tree->Branch((m_label + "_phiBCMSSW").c_str(), &m_lt_phiBCMSSW);

  m_tree->Branch((m_label + "_posLoc_x_raw").c_str(),  &m_lt_posLoc_x_raw);
  m_tree->Branch((m_label + "_posLoc_x").c_str(),  &m_lt_posLoc_x);
  m_tree->Branch((m_label + "_dirLoc_phi").c_str(), &m_lt_dirLoc_phi);
  m_tree->Branch((m_label + "_dirLoc_phi_raw").c_str(), &m_lt_dirLoc_phi_raw);

  m_tree->Branch((m_label + "_BX").c_str(),    &m_lt_bx);
  m_tree->Branch((m_label + "_t0").c_str(),    &m_lt_t0);

  m_tree->Branch((m_label + "_index").c_str(),    &m_lt_index);
  
  m_tree->Branch((m_label + "_pathWireId").c_str(),    &m_lt_pathWireId);
  m_tree->Branch((m_label + "_pathTDC").c_str(),    &m_lt_pathTDC);
  m_tree->Branch((m_label + "_pathLat").c_str(),    &m_lt_pathLat);

}

void DTNtuplePh2TPGPhiFiller::clear()
{

  m_nTrigs = 0;

  m_lt_wheel.clear();
  m_lt_sector.clear();
  m_lt_station.clear();

  m_lt_quality.clear();
  m_lt_superLayer.clear();

  m_lt_rpcFlag.clear();
  m_lt_chi2.clear();

  m_lt_phi.clear();
  m_lt_phiB.clear();

  m_lt_phiCMSSW.clear();
  m_lt_phiBCMSSW.clear();

  m_lt_posLoc_x_raw.clear();
  m_lt_posLoc_x.clear();
  m_lt_dirLoc_phi.clear();
  m_lt_dirLoc_phi_raw.clear();

  m_lt_bx.clear();
  m_lt_t0.clear();

  m_lt_index.clear();

  m_lt_pathWireId.clear();
  m_lt_pathTDC.clear();
  m_lt_pathLat.clear();

}

void DTNtuplePh2TPGPhiFiller::fill(const edm::Event & ev)
{

  clear();

  // if (!m_config->m_boolParams["useExtDataformat"]) auto trigColl = conditionalGet<L1Phase2MuDTPhContainer>(ev, m_dtTriggerToken,"L1Phase2MuDTPhContainer");
  auto trigColl = conditionalGet<L1Phase2MuDTExtPhContainer>(ev, m_dtTriggerTokenExt, "L1Phase2MuDTExtPhContainer");

  if (trigColl.isValid()) {
    const auto trigs = trigColl->getContainer();
    for(const auto & trig : (*trigs)) {
      m_lt_wheel.push_back(trig.whNum());
      m_lt_sector.push_back(trig.scNum() + 1);
      m_lt_station.push_back(trig.stNum());

      m_lt_quality.push_back(trig.quality());
      m_lt_superLayer.push_back(trig.slNum());

      m_lt_rpcFlag.push_back(trig.rpcFlag());
      m_lt_chi2.push_back(trig.chi2());

      m_lt_phi.push_back(trig.phi());
      m_lt_phiB.push_back(trig.phiBend());

      if (m_config->m_boolParams["useExtDataformat"]) {
        m_lt_phiCMSSW.push_back(trig.phiCMSSW());
        m_lt_phiBCMSSW.push_back(trig.phiBendCMSSW());

        float position = trig.xLocal() / 1000.;
        float slope = trig.tanPsi() / 1000.;
        if (m_config->m_boolParams["shift_coordinates"]) {
          int max_drift_tdc = maxdriftinfo_[trig.whNum() + 2][trig.stNum() - 1][trig.scNum()];
          DTWireId wireId(trig.whNum(), trig.stNum(), trig.scNum() + 1, 1, 2, 1);
          position *= ((float) cmsdt::CELL_SEMILENGTH / (float) max_drift_tdc) / 10;
          position += (cmsdt::SL1_CELLS_OFFSET * cmsdt::CELL_LENGTH) / 10.;
          position += shiftinfo_[wireId.rawId()];
          int sl = trig.slNum();
          if (sl == 1) sl = -1;
          else if (sl == 3) sl = 1;
          slope = -slope * ((float) CELL_SEMILENGTH / max_drift_tdc) * (1) / (CELL_SEMIHEIGHT * 16.);
          position -= sl * slope * cmsdt::VERT_PHI1_PHI3 / 2;
        }

        m_lt_posLoc_x_raw.push_back(position);
        m_lt_dirLoc_phi_raw.push_back(slope);

        std::vector<short> pathWireId;
        std::vector<int> pathTDC;
        std::vector<short> pathLat;

        for (int i = 0; i < 8; i++){
          pathWireId.push_back(trig.pathWireId(i));
          pathTDC.push_back(trig.pathTDC(i));
          pathLat.push_back(trig.pathLat(i));
        }

        m_lt_pathWireId.push_back(pathWireId);
        m_lt_pathTDC.push_back(pathTDC);
        m_lt_pathLat.push_back(pathLat);
      }

      m_lt_posLoc_x.push_back(m_tag == TriggerTag::HB ?
        m_config->m_trigGeomUtils->trigPosCHT(&trig) :
        m_config->m_trigGeomUtils->trigPosAM(&trig)  );
      m_lt_dirLoc_phi.push_back(m_tag == TriggerTag::HB ?
        m_config->m_trigGeomUtils->trigDirCHT(&trig) :
        m_config->m_trigGeomUtils->trigDirAM(&trig));

      m_lt_bx.push_back(trig.bxNum());
      m_lt_t0.push_back(trig.t0());

      m_lt_index.push_back(trig.index());

      m_nTrigs++;

    }
  }
  
  return;

}

