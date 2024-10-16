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

DTNtupleRPCDigiFiller::DTNtupleRPCDigiFiller(edm::ConsumesCollector && collector,
				       const std::shared_ptr<DTNtupleConfig> config, 
				       std::shared_ptr<TTree> tree, const std::string & label,
				       RpcDigiTag tag) : 
  DTNtupleBaseFiller(config, tree, label), m_tag(tag)
{

  edm::InputTag & iTag = m_tag == RpcDigiTag::PH1 ?
                                  m_config->m_inputTags["ph1RpcDigiTag"] :
                                  m_config->m_inputTags["ph2RpcDigiTag"];

  if (iTag.label() != "none") m_rpcDigiToken = collector.consumes<RPCDigiCollection>(iTag);

}

DTNtupleRPCDigiFiller::~DTNtupleRPCDigiFiller() 
{ 

};

void DTNtupleRPCDigiFiller::initialize()
{
  
  m_tree->Branch((m_label + "_nDigis").c_str(), &m_nDigis, (m_label + "_nDigis/i").c_str());
  
  /*m_tree->Branch((m_label + "_wheel").c_str(),   &m_digi_wheel);
  m_tree->Branch((m_label + "_sector").c_str(),  &m_digi_sector);
  m_tree->Branch((m_label + "_station").c_str(), &m_digi_station);

  m_tree->Branch((m_label + "_superLayer").c_str(), &m_digi_superLayer);
  m_tree->Branch((m_label + "_layer").c_str(),      &m_digi_layer);
  m_tree->Branch((m_label + "_wire").c_str(),       &m_digi_wire);

  m_tree->Branch((m_label + "_time").c_str(), &m_digi_time);*/
  
}

void DTNtupleRPCDigiFiller::clear()
{

  m_nDigis = 0;

  /*m_digi_wheel.clear();
  m_digi_sector.clear();
  m_digi_station.clear();

  m_digi_superLayer.clear();
  m_digi_layer.clear();
  m_digi_wire.clear();

  m_digi_time.clear();*/

}

void DTNtupleRPCDigiFiller::fill(const edm::Event & ev)
{

  clear();

  auto rpcDigis = conditionalGet<RPCDigiCollection>(ev, m_rpcDigiToken,"RPCDigiCollection");

  if (rpcDigis.isValid()) 
    {
      
      /*auto rpcLayerIdIt  = rpcDigis->begin();
      auto rpcLayerIdEnd = rpcDigis->end();
      
      for (; rpcLayerIdIt != rpcLayerIdEnd; ++rpcLayerIdIt)
	{

	  const auto & rpcLayerId = (*rpcLayerIdIt).first;

	  auto digiIt  = (*rpcLayerIdIt).second.first;
	  auto digiEnd = (*rpcLayerIdIt).second.second;
	  
	  for (; digiIt != digiEnd; ++digiIt)
	    {
	      m_digi_wheel.push_back(dtLayerId.wheel());
	      m_digi_sector.push_back(dtLayerId.sector());
	      m_digi_station.push_back(dtLayerId.station());

	      m_digi_superLayer.push_back(dtLayerId.superLayer());
	      m_digi_layer.push_back(dtLayerId.layer());
	      m_digi_wire.push_back(digiIt->wire());

	      m_digi_time.push_back(digiIt->time());
	      
	      m_nDigis++;

	    }
	}*/
    }
  
  return;

}

