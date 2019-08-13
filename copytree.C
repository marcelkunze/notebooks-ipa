void copytree() {
    TFile *oldfile;
    oldfile = new TFile("PidTuple.root");
    TTree *oldtree = (TTree*)oldfile->Get("PidTuple");
    TFile *newfile = new TFile("pid.root","recreate");
    TTree *newtree = oldtree->CloneTree();
    
    Float_t pid,charge,electron,muon,pion,kaon,proton;
    newtree->SetBranchAddress("pid",&pid);
    TBranch *cBranch = newtree->Branch("charge",&charge,"charge/F");
    TBranch *eBranch = newtree->Branch("electron",&electron,"electron/F");
    TBranch *mBranch = newtree->Branch("muon",&muon,"muon/F");
    TBranch *pBranch = newtree->Branch("pion",&pion,"pion/F");
    TBranch *kBranch = newtree->Branch("kaon",&kaon,"kaon/F");
    TBranch *prBranch = newtree->Branch("proton",&proton,"proton/F");
    
    Int_t nentries = (Int_t)newtree->GetEntries();
    for (Int_t i=0; i<nentries; i++) {
        newtree->GetEntry(i);
        charge = 1.0;
        if (pid<0) charge = -1.0;
        electron = (abs(pid) == 1);
        muon = (abs(pid) == 2);
        pion = (abs(pid) == 3);
        kaon = (abs(pid) == 4);
        proton = (abs(pid) == 5);
        cBranch->Fill();
        eBranch->Fill();
        mBranch->Fill();
        pBranch->Fill();
        kBranch->Fill();
        prBranch->Fill();
    }
    
    newtree->Print();
    newfile->Write();
    delete oldfile;
    delete newfile;
}
