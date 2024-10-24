/** \class DTNtupleRPCDigiFiller DTNtupleRPCDigiFiller.cc DTDPGAnalysis/DTNtuples/src/DTNtupleRPCDigiFiller.cc
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
     //m_rpcGeomToken = collector.consumes<RPCGeometry,MuonGeometryRecord>(iTag);
   }

}

DTNtupleRPCDigiFiller::~DTNtupleRPCDigiFiller() 
{ 

};

void DTNtupleRPCDigiFiller::initialize()
{
  
  m_tree->Branch((m_label + "_nDigis").c_str(), &m_nDigis, (m_label + "_nDigis/i").c_str());

  m_tree->Branch((m_label + "_region").c_str(),  &m_digi_region);
  m_tree->Branch((m_label + "_sector").c_str(),  &m_digi_sector);
  m_tree->Branch((m_label + "_station").c_str(), &m_digi_station);

  m_tree->Branch((m_label + "_strip").c_str(), &m_digi_strip);
  m_tree->Branch((m_label + "_BX").c_str(), &m_digi_bx);
  m_tree->Branch((m_label + "_time").c_str(), &m_digi_time);
  m_tree->Branch((m_label + "_coordinateX").c_str(), &m_digi_coordinateX);
  m_tree->Branch((m_label + "_coordinateY").c_str(), &m_digi_coordinateY);
  
}

void DTNtupleRPCDigiFiller::clear()
{

  m_nDigis = 0;

  m_digi_region.clear();
  m_digi_sector.clear();
  m_digi_station.clear();

  m_digi_strip.clear();
  m_digi_bx.clear();
  m_digi_time.clear();
  m_digi_coordinateX.clear();
  m_digi_coordinateY.clear();

}

void DTNtupleRPCDigiFiller::fill(const edm::Event & ev)
{

  clear();

  auto rpcDigis = conditionalGet<RPCDigiCollection>(ev, m_rpcDigiToken,"RPCDigiCollection");
  //auto rpcGeom = conditionalGet<RPCGeometry, MuonGeometryRecord>(ev, m_rpcGeomToken, "RPCGeometry");
  //auto rpcGeom = eventSetup.getHandle(m_rpcGeomToken);
  
  if (rpcDigis) //(rpcDigis.isValid()) FIXME 
   {
      auto rpcDetUnitIt = rpcDigis->begin();
      auto rpcDetUnitEnd = rpcDigis->end();

      for (; rpcDetUnitIt != rpcDetUnitEnd; ++rpcDetUnitIt)
        {

          const RPCDetId rsid = (*rpcDetUnitIt).first;
	  const RPCDigiCollection::Range &range = (*rpcDetUnitIt).second;

	  for (auto digiIt = range.first; digiIt != range.second; ++digiIt) 
	   {

              m_nDigis++;

	      m_digi_region.push_back(rsid.region());
              m_digi_sector.push_back(rsid.sector());
              m_digi_station.push_back(rsid.station());

	      m_digi_strip.push_back(digiIt->strip());
	      m_digi_bx.push_back(digiIt->bx());
	      m_digi_time.push_back(digiIt->time());
              m_digi_coordinateX.push_back(digiIt->coordinateX());
	      m_digi_coordinateY.push_back(digiIt->coordinateY());

	    }

	}
   }
  
  return;

}

