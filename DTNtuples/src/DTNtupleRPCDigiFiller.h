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

#include "FWCore/Utilities/interface/EDGetToken.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "Geometry/RPCGeometry/interface/RPCGeometry.h"
#include "Geometry/Records/interface/MuonGeometryRecord.h"


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
  virtual void fill(const edm::Event & ev, const edm::EventSetup & iSetup) final;

 private :

  /// Enum to activate "flavour-by-flavour"
  /// changes in the filling logic
  RpcDigiTag m_tag;

  /// The digi token
  edm::EDGetTokenT<RPCDigiCollection> m_rpcDigiToken;

  /// The RPC geometry token
  edm::ESGetToken<RPCGeometry, MuonGeometryRecord> rpcGeomToken_;

  /// The variables holding all digi related information (in barrel)

  unsigned int m_nDigis; 
 
  std::vector<short> m_digi_region; 	// 0 : barrel; +1, -1: endcaps
  std::vector<short> m_digi_wheel;      // -2, -1, 0, +1, +2
  std::vector<short> m_digi_sector;	// Same phi, different r: 1-12
  std::vector<short> m_digi_subsector;  // Subdividion of sectors along phi
  std::vector<short> m_digi_station;	// RBX; Same r, different phi: 1-4
  std::vector<short> m_digi_layer;	// 2 layers in RB1/RB2, 1 layer in RB3/RB4
  std::vector<short> m_digi_stla;	// Global layer: 1-6
  std::vector<short> m_digi_roll; 	// Eta partition; each chamber is divided along the strip direction in 2 or 3 rolls

  std::vector<int>  m_digi_strip;		// 1-96 strips / roll
  std::vector<int>  m_digi_bx;			// BX
  std::vector<int>  m_digi_sbx; 		// Sub-bx (will be implemented in future digi version)
  std::vector<double> m_digi_time;		// Fine time
  std::vector<double> m_digi_coordinateX;	// 0 in barrel (will be remove in future digi version)
  std::vector<double> m_digi_coordinateY;	// 0 in barrel (will be remove in future digi version)

};
  
#endif

