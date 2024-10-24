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

  if (iTag.label() != "none") m_rpcDigiToken = collector.consumes<RPCDigiCollection>(iTag);

}

DTNtupleRPCDigiFiller::~DTNtupleRPCDigiFiller() 
{ 

};

void DTNtupleRPCDigiFiller::initialize()
{
  
  m_tree->Branch((m_label + "_nDigis").c_str(), &m_nDigis, (m_label + "_nDigis/i").c_str());
  
  m_tree->Branch((m_label + "_strip").c_str(), &m_digi_strip);
  m_tree->Branch((m_label + "_BX").c_str(), &m_digi_bx);

  m_tree->Branch((m_label + "_time").c_str(), &m_digi_time);
  m_tree->Branch((m_label + "_coordinateX").c_str(), &m_digi_coordinateX);
  m_tree->Branch((m_label + "_coordinateY").c_str(), &m_digi_coordinateY);
  
}

void DTNtupleRPCDigiFiller::clear()
{

  m_nDigis = 0;

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
  
  if (rpcDigis) std::cout<<"Got an RPC Digi"<<std::endl;

  if (rpcDigis.isValid()) 
    {
      std::cout<<"Got a valid RPC Digi"<<std::endl;

      auto rpcDetIdIt = rpcDigis->begin();
      auto rpcDetIdEnd = rpcDigis->end();

      for (; rpcDetIdIt != rpcDetIdEnd; ++rpcDetIdIt)
        {
          const auto & rpcDetId = (*rpcDetIdIt).first;

	}
    }
  
  return;

}

