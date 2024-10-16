import FWCore.ParameterSet.Config as cms
import FWCore.ParameterSet.VarParsing as VarParsing
from Configuration.StandardSequences.Eras import eras

import subprocess
import sys

options = VarParsing.VarParsing()

options.register('globalTag',
                 '131X_mcRun4_realistic_v9', #default value
                 VarParsing.VarParsing.multiplicity.singleton,
                 VarParsing.VarParsing.varType.string,
                 "Global Tag")

options.register('nEvents',
                 -1, #default value
                 VarParsing.VarParsing.multiplicity.singleton,
                 VarParsing.VarParsing.varType.int,
                 "Maximum number of processed events")

options.register('inputFolder',
                 '/eos/cms/store/group/dpg_muon/rossin/Phase2/ParticleGun_thermalNeutrons_33BX_200_PU/step2/',
                 #'/eos/cms/store/group/dpg_muon/rossin/Phase2/ParticleGun_thermalNeutrons_33BX_200_PU/',
                 VarParsing.VarParsing.multiplicity.singleton,
                 VarParsing.VarParsing.varType.string,
                 "EOS folder with input files")

options.register('secondaryInputFolder',
                 '', #default value
                 VarParsing.VarParsing.multiplicity.singleton,
                 VarParsing.VarParsing.varType.string,
                 "EOS folder with input files for secondary files")

options.register('applySegmentAgeing',
                 False, #default value
                 VarParsing.VarParsing.multiplicity.singleton,
                 VarParsing.VarParsing.varType.bool,
                 "If True applies ageing to RECO segments")

options.register('applyTriggerAgeing',
                 False, #default value
                 VarParsing.VarParsing.multiplicity.singleton,
                 VarParsing.VarParsing.varType.bool,
                 "If True applies ageing to trigger emulators")

options.register('applyRpcAgeing',
                 False, #default value
                 VarParsing.VarParsing.multiplicity.singleton,
                 VarParsing.VarParsing.varType.bool,
                 "If True applies ageing to RPCs")

options.register('ageingInput',
                 '', #default value
                 VarParsing.VarParsing.multiplicity.singleton,
                 VarParsing.VarParsing.varType.string,
                 "Input with customised ageing, used only if non ''")

options.register('ageingTag',
                 'MuonSystemAging', #default value
                 VarParsing.VarParsing.multiplicity.singleton,
                 VarParsing.VarParsing.varType.string,
                 "Tag for customised ageing")

options.register('applyRandomBkg',
                 False, #default value
                 VarParsing.VarParsing.multiplicity.singleton,
                 VarParsing.VarParsing.varType.bool,
                 "If True applies random background to phase-2 digis and emulator")

options.register('ntupleName',
                 './DTDPGNtuple_11_1_0_patch2_Phase2_Simulation.root', #default value
                 VarParsing.VarParsing.multiplicity.singleton,
                 VarParsing.VarParsing.varType.string,
                 "Folder and name ame for output ntuple")

#options.register('qcut',
#                  5,
#                 VarParsing.VarParsing.multiplicity.singleton,
#                 VarParsing.VarParsing.varType.int,
#                 "th_quality")

options.parseArguments()

process = cms.Process("DTNTUPLES",eras.Phase2C9)

process.load('Configuration.StandardSequences.Services_cff')
process.load('FWCore.MessageService.MessageLogger_cfi')

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
process.MessageLogger.cerr.FwkReport.reportEvery = 100
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(options.nEvents))

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.GlobalTag.globaltag = cms.string(options.globalTag)

if options.ageingInput != "" :
    process.GlobalTag.toGet = cms.VPSet()
    process.GlobalTag.toGet.append(cms.PSet(record  = cms.string("MuonSystemAgingRcd"),
                                            connect = cms.string(options.ageingInput),
                                            tag     = cms.string(options.ageingTag)
                                        )
                               )

process.source = cms.Source("PoolSource",
                            
        fileNames = cms.untracked.vstring(),
        secondaryFileNames = cms.untracked.vstring()

)

files = subprocess.check_output(["ls", options.inputFolder])
process.source.fileNames = ["file://%s/%s" % (options.inputFolder, f.decode("utf-8")) for f in files.split()]
#process.source.fileNames = ["file://" + options.inputFolder + "/" + f for f in files.split()]

#process.source.fileNames = ["/store/mc/Phase2Fall22DRMiniAOD/MinBias_TuneCP5_14TeV-pythia8/GEN-SIM-DIGI-RAW-MINIAOD/PU200_125X_mcRun4_realistic_v2-v1/30000/001ec7cf-71d4-4eb4-9002-078d21560b2f.root"]


if options.secondaryInputFolder != "" :
    files = subprocess.check_output(["ls", options.secondaryInputFolder])
    process.source.secondaryFileNames = ["file://" + options.secondaryInputFolder + "/" + f for f in files.split()]

process.TFileService = cms.Service('TFileService',
        fileName = cms.string(options.ntupleName)
    )

process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.StandardSequences.Services_cff')
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load('Configuration.Geometry.GeometryExtended2026D95Reco_cff')

# process.DTGeometryESModule.applyAlignment = False
# process.DTGeometryESModule.fromDDD = False

process.load("L1Trigger.DTTriggerPhase2.CalibratedDigis_cfi") 
process.load("L1Trigger.DTTriggerPhase2.dtTriggerPhase2PrimitiveDigis_cfi")

process.CalibratedDigis.dtDigiTag = "simMuonDTDigis"
process.dtTriggerPhase2AmPrimitiveDigis = process.dtTriggerPhase2PrimitiveDigis.clone()
process.dtTriggerPhase2AmPrimitiveDigis.useRPC = True

process.load('RecoLocalMuon.Configuration.RecoLocalMuon_cff')
process.dt1DRecHits.dtDigiLabel = "simMuonDTDigis"
process.rpcRecHits.rpcDigiLabel = "simMuonRPCDigis"

from Configuration.StandardSequences.SimL1Emulator_cff import simBmtfDigis
process.simBmtfDigis = simBmtfDigis
process.simBmtfDigis.DTDigi_Source = "simDtTriggerPrimitiveDigis"
process.simBmtfDigis.DTDigi_Theta_Source = "simDtTriggerPrimitiveDigis"

process.load('DTDPGAnalysis.DTNtuples.dtNtupleProducer_phase2_cfi')

process.p = cms.Path(process.rpcRecHits
                     + process.dt1DRecHits
                     + process.dt4DSegments
                     + process.CalibratedDigis
                     + process.simBmtfDigis
                     + process.dtTriggerPhase2AmPrimitiveDigis
                     + process.dtNtupleProducer)

from DTDPGAnalysis.DTNtuples.customiseDtNtuples_cff import customiseForRandomBkg, customiseForRunningOnMC, customiseForFakePhase2Info, customiseForAgeing

customiseForRunningOnMC(process,"p")
customiseForFakePhase2Info(process)

if options.applyRandomBkg : 
    customiseForRandomBkg(process,"p")

customiseForAgeing(process,"p",options.applySegmentAgeing,options.applyTriggerAgeing,options.applyRpcAgeing)

#process.dtTriggerPhase2AmPrimitiveDigis.th_quality = cms.int32(options.qcut)

