#ifndef DTNtuple_DTNtupleRPCDigiFiller_h
#define DTNtuple_DTNtupleRPCDigiFiller_h

/** \class DTNtupleRPCDigiFiller DTNtupleRPCDigiFiller.h DTDPGAnalysis/DTNtuples/src/DTNtupleRPCDigiFiller.h
 *  
 * Helper class : the RPC digi filler for Phase-1 / Phase2 digis (the DataFormat is the same)
 *
 * \author C. Martin Perez (CIEMAT)
 *
 *
 */

#include "DTDPGAnalysis/DTNtuples/src/DTNtupleBaseFiller.h"

#include "DataFormats/RPCDigi/interface/RPCDigiCollection.h"

#include "FWCore/Framework/interface/ConsumesCollector.h"

#include <vector>

class DTNtupleRPCDigiFiller : public DTNtupleBaseFiller
{

 public:

  enum class RpcDigiTag { PH1 = 0, PH2 };

  /// Constructor
  DTNtupleRPCDigiFiller(edm::ConsumesCollector && collector,
		     const std::shared_ptr<DTNtupleConfig> config, 
		     std::shared_ptr<TTree> tree, const std::string & label, 
		     RpcDigiTag tag);

  ///Destructor
  virtual ~DTNtupleRPCDigiFiller();
 
  /// Intialize function : setup tree branches etc ... 
  virtual void initialize() final;
  
  /// Clear branches before event filling 
  virtual void clear() final;

  /// Fill tree branches for a given events
  virtual void fill(const edm::Event & ev) final;    

 private :

  /// Enum to activate "flavour-by-flavour"
  /// changes in the filling logic
  RpcDigiTag m_tag;

  /// The digi token
  edm::EDGetTokenT<RPCDigiCollection> m_rpcDigiToken;

  /// The variables holding
  /// all digi related information

  unsigned int m_nDigis; // the # of digis (size of all following vectors)

  std::vector<int>  m_digi_strip;   // strip
  std::vector<int>  m_digi_bx;      // bx
  
  std::vector<double> m_digi_time;        // time
  std::vector<double> m_digi_coordinateX; // coordinateX
  std::vector<double> m_digi_coordinateY; // coordinateY

};
  
#endif

