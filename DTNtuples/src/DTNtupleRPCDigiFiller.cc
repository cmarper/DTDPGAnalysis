/** \class DTNtDTNtupleRPCDigiFiller.ccupleRPCDigiFiller DTNtupleRPCDigiFiller.cc DTDPGAnalysis/DTNtuples/src/DTNtupleRPCDigiFiller.cc
 *  
 * Helper class : the RPC digi filler for Phase-1 / Phase2 digis (the DataFormat is the same)
 *
 * \author C. Martin Perez (CIEMAT)
 *
 *
 */

#include "DTDPGAnalysis/DTNtuples/src/DTNtupleRPCDigiFiller.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "DataFormats/MuonDetId/interface/RPCDetId.h"
#include "Geometry/RPCGeometry/interface/RPCGeometry.h"
#include "Geometry/RPCGeometry/interface/RPCRoll.h"

// Include these headers for type registration
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/PluginManager/interface/PluginFactory.h"
#include "FWCore/Utilities/interface/typelookup.h"

// Register the type RPCGeometry
TYPELOOKUP_DATA_REG(RPCGeometry);

DTNtupleRPCDigiFiller::DTNtupleRPCDigiFiller(edm::ConsumesCollector && collector,
                                             const std::shared_ptr<DTNtupleConfig> config, 
                                             std::shared_ptr<TTree> tree, const std::string & label,
                                             RpcDigiTag tag) : 
  DTNtupleBaseFiller(config, tree, label), m_tag(tag)
{
  edm::InputTag & iTag = m_tag == RpcDigiTag::PH1 ?
                                  m_config->m_inputTags["ph1RpcDigiTag"] :
                                  m_config->m_inputTags["ph2RpcDigiTag"];

  if (iTag.label() != "none")
  {
    m_rpcDigiToken = collector.consumes<RPCDigiCollection>(iTag);
    rpcGeomToken_ = collector.esConsumes<RPCGeometry, MuonGeometryRecord>();
  }
}

DTNtupleRPCDigiFiller::~DTNtupleRPCDigiFiller() 
{ 
}

void DTNtupleRPCDigiFiller::initialize()
{ 

  m_tree->Branch((m_label + "_nDigis").c_str(), &m_nDigis, (m_label + "_nDigis/i").c_str());

  m_tree->Branch((m_label + "_region").c_str(),  &m_digi_region);
  m_tree->Branch((m_label + "_wheel").c_str(),  &m_digi_wheel);
  m_tree->Branch((m_label + "_sector").c_str(),  &m_digi_sector);
  m_tree->Branch((m_label + "_subsector").c_str(),  &m_digi_subsector);
  m_tree->Branch((m_label + "_station").c_str(), &m_digi_station);
  m_tree->Branch((m_label + "_layer").c_str(), &m_digi_layer);
  m_tree->Branch((m_label + "_stla").c_str(), &m_digi_stla);
  m_tree->Branch((m_label + "_roll").c_str(), &m_digi_roll);

  m_tree->Branch((m_label + "_strip").c_str(), &m_digi_strip);
  m_tree->Branch((m_label + "_BX").c_str(), &m_digi_bx);
  m_tree->Branch((m_label + "_subBX").c_str(), &m_digi_sbx);
  m_tree->Branch((m_label + "_time").c_str(), &m_digi_time);

  m_tree->Branch((m_label + "_localPhi").c_str(), &m_digi_localPhi);
  m_tree->Branch((m_label + "_localEta").c_str(), &m_digi_localEta);
  m_tree->Branch((m_label + "_localR").c_str(), &m_digi_localR);
  m_tree->Branch((m_label + "_localX").c_str(), &m_digi_localX);
  m_tree->Branch((m_label + "_localY").c_str(), &m_digi_localY);
  m_tree->Branch((m_label + "_localZ").c_str(), &m_digi_localZ);

  m_tree->Branch((m_label + "_globalPhi").c_str(), &m_digi_globalPhi);
  m_tree->Branch((m_label + "_globalEta").c_str(), &m_digi_globalEta);
  m_tree->Branch((m_label + "_globalR").c_str(), &m_digi_globalR);
  m_tree->Branch((m_label + "_globalX").c_str(), &m_digi_globalX);
  m_tree->Branch((m_label + "_globalY").c_str(), &m_digi_globalY);
  m_tree->Branch((m_label + "_globalZ").c_str(), &m_digi_globalZ);

}

void DTNtupleRPCDigiFiller::clear()
{
  m_nDigis = 0;

  m_digi_region.clear();
  m_digi_wheel.clear();
  m_digi_sector.clear();
  m_digi_subsector.clear();
  m_digi_station.clear();
  m_digi_stla.clear();
  m_digi_layer.clear();
  m_digi_roll.clear();

  m_digi_strip.clear();
  m_digi_bx.clear();
  m_digi_sbx.clear();
  m_digi_time.clear();

  m_digi_localPhi.clear();
  m_digi_localEta.clear();
  m_digi_localR.clear();
  m_digi_localX.clear();
  m_digi_localY.clear();
  m_digi_localZ.clear(); 

  m_digi_globalPhi.clear();
  m_digi_globalEta.clear();
  m_digi_globalR.clear();
  m_digi_globalX.clear();
  m_digi_globalY.clear();
  m_digi_globalZ.clear();
 
}

void DTNtupleRPCDigiFiller::fill(const edm::Event &ev, const edm::EventSetup &iSetup)
{
  clear();

  auto rpcDigis = conditionalGet<RPCDigiCollection>(ev, m_rpcDigiToken, "RPCDigiCollection");
  if (rpcDigis) 
  {
    edm::ESHandle<RPCGeometry> rpcGeometry = iSetup.getHandle(rpcGeomToken_);

    if (!rpcGeometry) {
      std::cerr << "RPCGeometry is null!" << std::endl;
      return;
    }

    auto rpcDetUnitIt = rpcDigis->begin();
    auto rpcDetUnitEnd = rpcDigis->end();

    for (; rpcDetUnitIt != rpcDetUnitEnd; ++rpcDetUnitIt)
    {
      const RPCDetId rsid = (*rpcDetUnitIt).first;
      const RPCDigiCollection::Range &range = (*rpcDetUnitIt).second;

      const RPCRoll* roll = rpcGeometry->roll(rsid);

      if (!roll) {
        //std::cerr << "RPCRoll is null for rsid: " << rsid << std::endl;
        continue;
      } 

      for (auto digiIt = range.first; digiIt != range.second; ++digiIt)
      {
        m_nDigis++;

        int strip = digiIt->strip();

        m_digi_region.push_back(rsid.region());
        m_digi_wheel.push_back(rsid.ring());
        m_digi_sector.push_back(rsid.sector());
        m_digi_subsector.push_back(rsid.subsector());
        m_digi_station.push_back(rsid.station());
        m_digi_layer.push_back(rsid.layer());
        int stla = (rsid.station() <= 2) ? (2 * (rsid.station() - 1) + rsid.layer()) : (rsid.station() + 2);
        m_digi_stla.push_back(stla);
        m_digi_roll.push_back(rsid.roll());
        m_digi_strip.push_back(strip);
        m_digi_bx.push_back(digiIt->bx());
        m_digi_sbx.push_back(-999);
        m_digi_time.push_back(digiIt->time());

        LocalPoint stripPositionLocal = roll->centreOfStrip(strip);

        double localPhi = stripPositionLocal.phi();
        double localEta = stripPositionLocal.eta();
        double localR = stripPositionLocal.perp();
        double localX = stripPositionLocal.x();
        double localY = stripPositionLocal.y();
        double localZ = stripPositionLocal.z();

        m_digi_localPhi.push_back(localPhi);
        m_digi_localEta.push_back(localEta);
        m_digi_localR.push_back(localR);
        m_digi_localX.push_back(localX);
        m_digi_localY.push_back(localY);
        m_digi_localZ.push_back(localZ);

        GlobalPoint stripPositionGlobal = roll->toGlobal(roll->centreOfStrip(strip));
        
        double globalPhi = stripPositionGlobal.phi();
        double globalEta = stripPositionGlobal.eta();
        double globalR = stripPositionGlobal.perp();
        double globalX = stripPositionGlobal.x();
        double globalY = stripPositionGlobal.y();
        double globalZ = stripPositionGlobal.z();

        m_digi_globalPhi.push_back(globalPhi);
        m_digi_globalEta.push_back(globalEta);
        m_digi_globalR.push_back(globalR);
        m_digi_globalX.push_back(globalX);
        m_digi_globalY.push_back(globalY);
        m_digi_globalZ.push_back(globalZ);

      }
    }
  }

  return;

}
