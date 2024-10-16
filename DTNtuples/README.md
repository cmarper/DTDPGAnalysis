# DTNtuples
Ntuples for the analysis of the CMS drift tubes detector performance

## Preliminary instructions
**Note**: 
In the present days this code is evolving fast, hence the installation recipe may change often. Please keep an eye on this page to check for updates.

### Installation:
```bash
cmsrel CMSSW_14_2_0_pre1
cd CMSSW_14_2_0_pre1/src
cmsenv

git cms-addpkg L1Trigger/DTTriggerPhase2
git cms-addpkg SimMuon/DTDigitizer

git clone https://github.com/cms-data/L1Trigger-DTTriggerPhase2/ L1Trigger/DTTriggerPhase2/data

git clone https://github.com/cmarper/DTDPGAnalysis.git
```

### Ntuple production:
```
# No ageing
cmsRun dtDpgNtuples_phase2_cfg.py nEvents=100 applyTriggerAgeing=False ntupleName=test.root 

#Ageing
cmsRun dtDpgNtuples_phase2_cfg.py nEvents=50 applyTriggerAgeing=True ageingTag='MuonAgeingAndFailures_3000fbm1_DT_L1TTDR' ageingInput='sqlite_file:MuonAgeingAndFailures_3000fbm1_DT_L1TTDR_v1_mc.db' ntupleName=test-ageing.root
```
