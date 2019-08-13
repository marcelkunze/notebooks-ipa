void copytree() {
    TFile *oldfile;
    oldfile = new TFile("PidTuple.root");
    TTree *oldtree = (TTree*)oldfile->Get("PidTuple");
    TFile *newfile = new TFile("pid.root","recreate");
    TTree *newtree = oldtree->CloneTree();
    
    Int_t id;
    Float_t pid,charge,electron,muon,pion,kaon,proton;
    newtree->SetBranchAddress("pid",&pid);
    TBranch *cBranch = newtree->Branch("charge",&charge,"charge/F");
    TBranch *idBranch = newtree->Branch("id",&id,"id/I");

    Int_t nentries = (Int_t)newtree->GetEntries();
    for (Int_t i=0; i<nentries; i++) {
        newtree->GetEntry(i);
        charge = 1.0;
        if (pid<0) charge = -1.0;
        cBranch->Fill();
        id = abs(pid) - 1;
        idBranch->Fill();
    }
    
    newtree->Print();
    newfile->Write();
    delete oldfile;
    delete newfile;
}
