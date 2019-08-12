void copytree() {
   gSystem->Load("$ROOTSYS/test/libEvent");
   //Get old file, old tree and set top branch address
   TFile *oldfile;
   oldfile = new TFile("PidTuple.root");
   TTree *oldtree = (TTree*)oldfile->Get("PidTuple");
   //Event *event   = new Event();
   //oldtree->SetBranchAddress("event",&event);
   //oldtree->SetBranchStatus("*",0);
   //oldtree->SetBranchStatus("event",1);
   //oldtree->SetBranchStatus("fNtrack",1);
   //oldtree->SetBranchStatus("fNseg",1);
   //oldtree->SetBranchStatus("fH",1);
   //Create a new file + a clone of old tree in new file
   TFile *newfile = new TFile("small.root","recreate");
   TTree *newtree = oldtree->CloneTree();
   newtree->Print();
   newfile->Write();
   delete oldfile;
   delete newfile;
}
