#define DTTREEgun_cxx
#include "DTTREEgun.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
void DTTREEgun::Loop()
{
//   In a ROOT session, you can do:
//      root> .L DTTREEgun.C
//      root> DTTREEgun t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

   float vwire = 24.4 ; // cm/ns
//   float zFE[5] = {-654., -389., 123., 389., 654.}; //cm
//   float xFE[3] = {199/2., 245/2., 303/2.};//cm
   float zFE[5] = {-658.9, -393.3, 126.4, 393.3, 658.9}; //cm
   float xFE[3] = {218/2., 266.8/2., 315/2.};//cm
   float ZRES_CONV = 65536. / 1500;
   const int firstNtp=5;

   if (fChain == 0) return;
   TFile *f = new TFile("testGun.root","RECREATE");

   TH1F *tphiMatched = new TH1F("tphiMatched","tphiMatched",50,-25,25);
   TH1F *tphiMatched_ring[15][firstNtp+1];
   TH1F *t0Matched = new TH1F("t0Matched","t0Matched",50,-25,25);
   TH1F *t0Matched_ring[15][firstNtp+1];
   for (uint st = 1; st <4; ++st){
   for(int w=-2;w<3;++w){
   uint i = st-1+3*(w+2);
   for (uint nm = 0; nm <firstNtp+1; ++nm){
   stringstream namestream1ring;
   namestream1ring << "tphiMatched_MB"<<st<<"_W"<<w<<"_closest_"<<nm<<"_TPs";
   tphiMatched_ring[i][nm] = new TH1F(namestream1ring.str().c_str(),namestream1ring.str().c_str(),50,-25,25);
   stringstream namestream2ring;
   namestream2ring << "t0Matched_MB"<<st<<"_W"<<w<<"_closest_"<<nm<<"_TPs";
   t0Matched_ring[i][nm] = new TH1F(namestream2ring.str().c_str(),namestream2ring.str().c_str(),50,-25,25);
   }}}


   TH1F *nMatched = new TH1F("nMatched","nMatched",2,0,2);
   TH2F *nMatchedMap[firstNtp+1];
   TH2F *nReductionMap[firstNtp+1];
   for (uint nm = 0; nm <firstNtp+1; ++nm){
   stringstream namestream1ring;
   namestream1ring << "nMatched_closest_"<<nm<<"_TPs";
   nMatchedMap[nm] = new TH2F(namestream1ring.str().c_str(),namestream1ring.str().c_str(),5,-2.5,2.5,3,0.5,3.5);
   stringstream namestream;
   namestream<< "nReductionMap_closest_"<<nm<<"_TPs";
   nReductionMap[nm] = new TH2F(namestream.str().c_str(),namestream.str().c_str(),5,-2.5,2.5,3,0.5,3.5);
   }

   TH2F *nTotMap = new TH2F("nTotMap","nTotMap",5,-2.5,2.5,3,0.5,3.5);
   TH1F *nReduction = new TH1F("nReduction","nReduction",10,0,1);
   TH2F *nTotCombMap = new TH2F("nTotCombMap","nTotCombMap",5,-2.5,2.5,3,0.5,3.5);
   TH2F *qVSdca = new TH2F("qVSdca","qVSdca",100,0,50,9,0,9);
   TH2F *qVSdistance = new TH2F("qVSdistance","qVSdistance",100,0,50,9,0,9);
   TH2F *qThetaVSdca = new TH2F("qThetaVSdca","qThetaVSdca",100,0,50,4,0,4);
   TH2F *qThetaVSdistance = new TH2F("qThetaVSdistance","qThetaVSdistance",100,0,50,4,0,4);

   TH1F *nReductionChamber[15];
   for (uint st = 1; st <4; ++st){
   for(int w=-2;w<3;++w){
   uint i = st-1+3*(w+2);
   stringstream namestream1ring;
   namestream1ring << "nReduction_MB"<<st<<"_W"<<w;
   nReductionChamber[i] = new TH1F(namestream1ring.str().c_str(),namestream1ring.str().c_str(),10,0,1);
   }}


   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

   for (uint i = 0; i < gen_nGenParts; ++i) {
      if (abs(gen_pdgId->at(i)) != 13) continue; //1000015 //13)  continue;
      if (gen_pt->at(i)<20) continue;
      
      for (Int_t iStationToLook = 1; iStationToLook <4; ++iStationToLook){
	// look for seg

	int iBestSeg = BestSeg(i, iStationToLook);
	if (iBestSeg < 0) continue;	      
	if (seg_hasZed->at(iBestSeg)!=1) continue;
	if (seg_phi_nHits->at(iBestSeg)<4) continue;

	int wheel = seg_wheel->at(iBestSeg);
	int index=iStationToLook-1+3*(wheel+2);
	
	// look for trig

	int trigQual=1;
	int iTrig = BestTrig(iBestSeg, iStationToLook, wheel, trigQual);
	if (iTrig<0) continue;

	// with or without corrections?
//        bool correct = true;
//	if (correct && iStationToLook<4) trigtime=ph2TpgPhiEmuAm_t0->at(iTrig)-500-trigFunctions[wheel][iStationToLook]->Eval(seg_posLoc_y->at(iBestSeg));
//	else trigtime=ph2TpgPhiEmuAm_t0->at(iTrig)-500;

        int trigQualZ=1;
        int iTrigZ = BestTrigZ(iBestSeg, iStationToLook, wheel, trigQualZ);
        if(iTrigZ<0) continue;

        int sector = 0;
        if(ph2TpgThetaEmuAm_sector->at(iTrigZ) != ph2TpgPhiEmuAm_sector->at(iTrig)) continue;
        else sector = ph2TpgThetaEmuAm_sector->at(iTrigZ);
        
        float deltaTimePos[5]={999999.,999999.,999999.,999999.,999999.};
        int goodPhi[5] = {-1,-1,-1,-1,-1};
        int goodTheta[5] = {-1,-1,-1,-1,-1};
        int nPhi=0;
        int nTheta=0;
        float goodTphi=999.;
        float goodTPSL13=999.;

        for (Int_t iTheta=0;iTheta<ph2TpgThetaEmuAm_nTrigs;iTheta++){
            if(ph2TpgThetaEmuAm_station->at(iTheta)!=iStationToLook) continue;
            if(ph2TpgThetaEmuAm_wheel->at(iTheta)!=wheel) continue;
            if(ph2TpgThetaEmuAm_sector->at(iTheta)!=sector) continue;
            nTheta++;
            for (Int_t iPhi=0;iPhi<ph2TpgPhiEmuAm_nTrigs;iPhi++){
          
                     if(ph2TpgPhiEmuAm_station->at(iPhi)!=iStationToLook) continue;
                     if(ph2TpgPhiEmuAm_wheel->at(iPhi)!=wheel) continue;
                     if(ph2TpgPhiEmuAm_sector->at(iPhi)!=sector) continue;
                     if(nTheta<2) nPhi++;
                     nTotCombMap->Fill(wheel,iStationToLook);

                     float t0theta = ph2TpgThetaEmuAm_t0->at(iTheta);
                     float t0phi = ph2TpgPhiEmuAm_t0->at(iPhi);
                     int wh = wheel;
                     int se = sector;
                     int st = iStationToLook;
                     
                     float posRefZ = zFE[wh+2];
                     if(wh==0 && (se ==1 || se==4 || se==5 || se==8 || se==9 ||se==12)) posRefZ = -posRefZ;
                     //cout<<"posRefZ: "<<posRefZ<<" Z: "<<(ph2TpgThetaEmuAm_z->at(iTrigZ))/ZRES_CONV<<endl;
                     float tphi = t0phi-abs((ph2TpgThetaEmuAm_z->at(iTheta))/ZRES_CONV -posRefZ)/vwire;
                     //cout<<"tphi: "<<tphi<<endl;
                     int LR = -1;
                     if(wh==0 && (se==3 || se==4 || se==7 || se==8 || se==11 || se==12)) LR = +1;
                     else if (wh>0) LR = pow(-1,wh+se+1);
                     else if (wh<0) LR = pow(-1,-wh+se);
                     //cout<<"wh st se: "<< wh <<" "<< st <<" "<< se <<" LR: "<< LR<<endl;
                     float posRefX = LR*xFE[st-1];
                     float ttheta =t0theta-(ph2TpgPhiEmuAm_posLoc_x->at(iPhi) -posRefX)/vwire;
                     //cout<<"posRefX: "<< posRefX<<" X: "<<ph2TpgPhiEmuAm_posLoc_x->at(iTrig)<<endl;
                     //cout<<"ttheta: "<<ttheta<<endl;
                     //cout<<"iPhi: "<<iPhi<<" Q: "<<ph2TpgPhiEmuAm_quality->at(iPhi)<<" iTheta: "<< iTheta<<" Q: "<<ph2TpgThetaEmuAm_quality->at(iTheta)<<" tphi-ttheta: "<<(tphi-ttheta) <<endl;
		     qVSdistance->Fill(abs(tphi-ttheta),ph2TpgPhiEmuAm_quality->at(iPhi));
		     qThetaVSdistance->Fill(abs(tphi-ttheta),ph2TpgThetaEmuAm_quality->at(iTheta));

                     for (int icount=0;icount<firstNtp;icount++){
                     if(abs(deltaTimePos[icount])>abs(tphi-ttheta)){
                           for(int ircount=firstNtp-1;ircount>icount;ircount--){
                              deltaTimePos[ircount]=deltaTimePos[ircount-1];
                              goodPhi[ircount]=goodPhi[ircount-1];
                              goodTheta[ircount]=goodTheta[ircount-1];}
                           deltaTimePos[icount]=(tphi-ttheta);
                           goodPhi[icount] = iPhi;
                           goodTheta[icount]= iTheta;
                           goodTphi=tphi+250./2/vwire;
                           goodTPSL13=t0phi;
                           //cout<<"deltaTimePos: "<<deltaTimePos[icount]<<" goodPhi: "<<goodPhi[icount]<<endl;
                           break;
                     }}
            }//loop in Phi
        }//loop in Theta

        qVSdca->Fill(abs(deltaTimePos[0]),ph2TpgPhiEmuAm_quality->at(goodPhi[0]));
        qThetaVSdca->Fill(abs(deltaTimePos[0]),ph2TpgThetaEmuAm_quality->at(goodTheta[0]));

        if(nTheta<1) continue; //count only chambers where multiplicity >1
        nTotMap->Fill(wheel,iStationToLook);
        bool matched=false;
        for (int icount = 0; icount<firstNtp;icount++){
             //cout<<"deltaTimePos: "<<deltaTimePos[icount]<<" goodPhi: "<<goodPhi[icount]<<endl;
             if(matched) continue;
             if(goodPhi[icount]==iTrig && iTrigZ==goodTheta[icount]) {//cout<<"Match!!!"<<endl;
             nMatchedMap[icount+1]->Fill(wheel,iStationToLook);
             nMatchedMap[0]->Fill(wheel,iStationToLook);
             nMatched->Fill(1);
             tphiMatched->Fill(goodTphi-500);
             tphiMatched_ring[index][icount+1]->Fill(goodTphi-500);
             tphiMatched_ring[index][0]->Fill(goodTphi-500);
             t0Matched->Fill(goodTPSL13-500);
             t0Matched_ring[index][icount+1]->Fill(goodTPSL13-500);
             t0Matched_ring[index][0]->Fill(goodTPSL13-500);
             nReduction->Fill((icount+1.)/(nPhi*nTheta));
             nReductionChamber[index]->Fill((icount+1.)/(nPhi*nTheta));
             nReductionMap[0]->Fill(wheel,iStationToLook);
             nReductionMap[icount+1]->Fill(wheel,iStationToLook);
             matched=true;}
        }
        if(!matched){cout<<"nPhi: "<<nPhi<<" nTheta: "<<nTheta<<endl; 
             //cout<<"iTrig: "<<iTrig<<" iTrigZ: "<<iTrigZ<<endl;
            nMatched->Fill(0);}

   }//loop in station
}//particles

}//entry
f->Write();
}
