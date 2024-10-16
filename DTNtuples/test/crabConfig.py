from WMCore.Configuration import Configuration
config = Configuration()
from samples import samples


################### MODIFY THESE TWO PARAMETERS ###############
bkgUsed = "0" ## This one just sets filenames, need to modify it in plugins/DTRandomDigiGenerator.cc and recompile
useRPC = False
ageing = False
sampleUsed = "nu_PU200" ## This alias can be found in test/samples.py
sampleUsed = "mu_PU140"
#algo = 'AMThetaLocalY' 
#algo = 'Parallel'
#algo = 'ParallelAM'
#algo = 'Mixed'
#algo = 'Parallel22'
#algo = 'ParallelBayesFilteredSameBXCousins'
#algo = 'ParallelAMFiltered'
algo = 'qcut0'

##### Configuration parameters ################################
inputDataset = samples[sampleUsed]

# These are the cfg parameters used to configure the 
# dtDpgNtuples_slicetest_cfg.py configuration file
configParams = ['qcut=0', 'ntupleName=DTDPGNtuple.root']
if bkgUsed != "0" : configParams.append('applyRandomBkg=True') 
if useRPC : configParams.append('useRPC=True')
if ageing : 
  configParams.append('applyTriggerAgeing=True')
  configParams.append('ageingTag=MuonAgeingAndFailures_3000fbm1_DT_L1TTDR') 
  configParams.append('ageingInput=sqlite_file:MuonAgeingAndFailures_3000fbm1_DT_L1TTDR_v1_mc.db')



# E.g. use dedicated tTrigs
# configParams = ['ntupleName=DTDPGNtuple.root', \
#                 'tTrigFile=calib/TTrigDB_cosmics_ttrig.db'] 

# These are the additional input files (e.g. sqlite .db) 
# needed by dtDpgNtuples_slicetest_cfg.py to run
if not ageing : inputFiles = ['L1Trigger/DTTriggerPhase2/data/'] 
else : inputFiles = ['L1Trigger/DTTriggerPhase2/data','./MuonAgeingAndFailures_3000fbm1_DT_L1TTDR_v1_mc.db']
# E.g. use dedicated tTrigs
# inputFiles = ['./calib/TTrigDB_cosmics_ttrig.db'] 

###############################################################

config.section_('General')
#config.General.workArea = 'crab_'+algo

requestName = 'DTDPGNtuples_' + sampleUsed + "_" +'algo'
if useRPC : requestName += '_withRPC'
else : requestName += '_noRPC'
if ageing: requestName += '_withAgeing'
else : requestName += '_noAgeing'
if bkgUsed != "0" : requestName += '_bkg' + bkgUsed
config.General.requestName = requestName+"_nocor_" + algo

config.General.transferOutputs = True

config.section_('JobType')
config.JobType.pluginName  = 'Analysis'
config.JobType.psetName    = algo+'.py'
config.JobType.psetName    = 'dtDpgNtuples_phase2_cfg.py'
config.JobType.allowUndistributedCMSSW = True

config.JobType.pyCfgParams = configParams
config.JobType.inputFiles  = inputFiles

config.section_('Data')
config.Data.inputDataset = inputDataset

config.Data.splitting    = 'LumiBased'
config.Data.unitsPerJob  = 1

if 'DM_Alberto' in sampleUsed :
  config.Data.inputDBS = 'phys03'

#config.Data.inputDBS     = 'https://cmsweb.cern.ch/dbs/prod/global/DBSReader/'
outName = '/store/user/jfernan/L1T/' + sampleUsed + "_" + algo
if useRPC : outName += '_withRPC'
else : outName += '_noRPC'
if ageing: outName += '_withAgeing'
else : outName += '_noAgeing'
if bkgUsed != "0" : outName += '_bkg' + bkgUsed
config.Data.outLFNDirBase  = outName+"_12_3_X"

config.section_('Site')
config.Site.storageSite = 'T3_CH_CERNBOX'

