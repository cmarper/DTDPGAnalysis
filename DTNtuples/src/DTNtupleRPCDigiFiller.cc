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
  m_tree->Branch((m_label + "_coordinateX").c_str(), &m_digi_coordinateX);
  m_tree->Branch((m_label + "_coordinateY").c_str(), &m_digi_coordinateY);
  
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
  m_digi_coordinateX.clear();
  m_digi_coordinateY.clear();

}

void DTNtupleRPCDigiFiller::fill(const edm::Event & ev)
{

  clear();

  auto rpcDigis = conditionalGet<RPCDigiCollection>(ev, m_rpcDigiToken,"RPCDigiCollection");
  
  if (rpcDigis) 
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
	      m_digi_wheel.push_back(rsid.ring());
              m_digi_sector.push_back(rsid.sector());
	      m_digi_subsector.push_back(rsid.subsector()); //FIXME
              m_digi_station.push_back(rsid.station());
	      m_digi_layer.push_back(rsid.layer());
	      int stla = (rsid.station() <= 2) ? (2 * (rsid.station() - 1) + rsid.layer()) : (rsid.station() + 2);
	      m_digi_stla.push_back(stla);
	      m_digi_roll.push_back(rsid.roll());

	      m_digi_strip.push_back(digiIt->strip());
	      m_digi_bx.push_back(digiIt->bx());
	      m_digi_sbx.push_back(-999); //FIXME
	      m_digi_time.push_back(digiIt->time());
              m_digi_coordinateX.push_back(digiIt->coordinateX());
	      m_digi_coordinateY.push_back(digiIt->coordinateY());

	    }

	}
   }
  
  return;

}

