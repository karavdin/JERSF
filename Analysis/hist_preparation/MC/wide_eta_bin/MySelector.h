//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Aug 13 16:05:52 2015 by ROOT version 5.34/32
// from TTree t/t
// found on file: /pnfs/desy.de/cms/tier2/store/user/mniedzie/Spring15_QCD_Pt-binned/QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8/JERmcSpring15/150810_142114/0000/output_mc_1.root
//////////////////////////////////////////////////////////

#ifndef MySelector_h
#define MySelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <TH1F.h>
#include <TH2F.h>
#include <TMath.h>
#include <TDirectory.h>

#include "MyJet.h"


// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxp4 = 164;
const Int_t kMaxgen_p4 = 164;

double Weight( std::string filename );

class MySelector : public TSelector {
  public :

  TTree *fChain;   //!pointer to the analyzed TTree or TChain

  // Declaration of leaf types

  Float_t         weight;
  Float_t         weight_pu;
  Float_t         weight_pu_down;
  Float_t         weight_pu_up;
  Float_t         pthat;
  Int_t           npuIT;
  Int_t njet;
  Float_t pt_ave;
  Float_t jet1_pt;
  Float_t jet2_pt;
  Float_t jet3_pt;
  Float_t barreljet_phi;
  Float_t barreljet_eta;
  Float_t barreljet_pt;
  Float_t probejet_phi;
  Float_t probejet_eta;
  Float_t probejet_pt;
  Float_t asymmetry;
  Float_t rho;
  Float_t alpha;
  TBranch *b_njet;
  TBranch *b_pt_ave;
  TBranch *b_jet1_pt;
  TBranch *b_jet2_pt;
  TBranch *b_jet3_pt;
  TBranch *b_probejet_phi;
  TBranch *b_probejet_eta;
  TBranch *b_probejet_pt;
  TBranch *b_barreljet_phi;
  TBranch *b_barreljet_eta;
  TBranch *b_barreljet_pt;
  TBranch *b_asymmetry;
  TBranch *b_alpha;
  TBranch *b_rho; // Read out from tree for smearing purposes

  Int_t ngenjet;
  Float_t gen_pt_ave;
  Float_t genjet1_pt;
  Float_t genjet2_pt;
  Float_t genjet3_pt;
  Float_t barrelgenjet_phi;
  Float_t barrelgenjet_eta;
  Float_t barrelgenjet_pt;
  Float_t probegenjet_phi;
  Float_t probegenjet_eta;
  Float_t probegenjet_pt;
  Float_t gen_asymmetry;
  Float_t gen_alpha;
  TBranch *b_ngenjet;
  TBranch *b_gen_pt_ave;
  TBranch *b_genjet1_pt;
  TBranch *b_genjet2_pt;
  TBranch *b_genjet3_pt;
  TBranch *b_probegenjet_phi;
  TBranch *b_probegenjet_eta;
  TBranch *b_probegenjet_pt;
  TBranch *b_barrelgenjet_phi;
  TBranch *b_barrelgenjet_eta;
  TBranch *b_barrelgenjet_pt;
  TBranch *b_gen_asymmetry;
  TBranch *b_gen_alpha;

  // List of branches
  TBranch        *b_weight;   //!
  TBranch        *b_weight_pu;   //!
  TBranch        *b_weight_pu_down;   //!
  TBranch        *b_weight_pu_up;   //!
  TBranch        *b_pthat;   //!
  TBranch        *b_npuIT;   //!

  MySelector(TTree * /*tree*/ =0) : fChain(0) { }
  virtual ~MySelector() { }
  virtual Int_t   Version() const { return 2; }
  virtual void    Begin(TTree *tree);
  virtual void    SlaveBegin(TTree *tree);
  virtual void    Init(TTree *tree);
  virtual Bool_t  Notify();
  virtual Bool_t  Process(Long64_t entry);
  virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) {
    int treeentry = entry;
    return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0;
  }
  virtual void    SetOption(const char *option) { fOption = option; }
  virtual void    SetObject(TObject *obj) { fObject = obj; }
  virtual void    SetInputList(TList *input) { fInput = input; }
  virtual TList  *GetOutputList() const { return fOutput; }
  virtual void    SlaveTerminate();
  virtual void    Terminate();

  void BuildEvent();
  void MakeWeight();

  std::vector<std::vector<double> > resolutions, scalefactors;
  std::vector <double> pileup_weight_factors;

  int TotalEvents, unmachedJets, unmatchegGenJets;
  int EtaForwardBinsNo;
  int EtaBinsNo;
  int EtaFtBinsNo;
  int EtaFtControlBinsNo;
  int PtBinsNo;
  int PtFTBinsNo;
  int AlphaBinsNo;

  std::vector< std::vector< std::vector< TH1F* > > > forward_hist, forward_gen_hist;
  std::vector< std::vector< std::vector< TH1F* > > > forward_hist_dijet, forward_gen_hist_dijet;
  std::vector< std::vector< std::vector< TH1F* > > > asymmetries_all, asymmetries_gen_all;

  std::vector< std::vector< std::vector< TH1F* > > > forward_pt_hist, forward_gen_pt_hist;
  std::vector< std::vector< std::vector< TH1F* > > > forward_pt_hist_dijet, forward_pt_gen_hist_dijet;
  std::vector< std::vector< std::vector< TH1F* > > > asymmetries_pt_all, asymmetries_gen_pt_all;

  std::vector< std::vector< std::vector< TH1F* > > > forward_pt3_hist, forward_gen_pt3_hist;
  std::vector< std::vector< std::vector< TH1F* > > > forward_pt3_hist_dijet, forward_gen_pt3_hist_dijet;
  std::vector< std::vector< std::vector< TH1F* > > > asymmetries_pt3_all, asymmetries_gen_pt3_all;

  std::vector< std::vector< std::vector< TH1F* > > > forward_rho_hist, forward_gen_rho_hist;
  std::vector< std::vector< std::vector< TH1F* > > > forward_rho_hist_dijet, forward_gen_rho_hist_dijet;
  std::vector< std::vector< std::vector< TH1F* > > > asymmetries_rho_all, asymmetries_gen_rho_all;


  std::vector< std::vector< std::vector< TH1F* > > > MC_Truth_asymmetries_all,
  MC_Truth_forward_hist,
  MC_Truth_forward_hist_dijet;

  std::vector< std::vector< TH1F* > > alpha_spectrum, forward_alpha_spectrum, forward_alpha_spectrum_dijet;

  std::vector<TH1F*> histograms;

  TH1F *make_histogram( TString name, int bin_no, double range_min, double range_max, TString xaxis, TString yaxis );

  TH1F *h_JetPt;
  TH1F *h_PU;

  TH1F *h_rho;
  TH1F *h_rhoFWD;

  TH1F *h_JetAvePt;
  TH1F *h_Jet1Pt;
  TH1F *h_Jet2Pt;
  TH1F *h_Jet3Pt;

  TH1F *h_FEJetAvePt;
  TH1F *h_FEJet1Pt;
  TH1F *h_FEJet2Pt;
  TH1F *h_FEJet3Pt;

  // ClassDef(MySelector,0);
};

#endif

#ifdef MySelector_cxx
void MySelector::Init(TTree *tree){
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set object pointer

  std::ifstream myfile, myfileSF;
  myfile.open("/nfs/dust/cms/user/niedziem/resolutions_input/Fall17_17Nov2017_V4_MC_PtResolution_ak4pfchsl1l2l3.txt");
  myfileSF.open("/nfs/dust/cms/user/sonnevej/resolutions_input/scalefactors/Spring16_25nsV6_MC_SF_AK4PFchs13invfb_pythiaHTbinnedfrom200.txt");

  std::string temp;

  while (std::getline(myfile, temp)) {
    std::istringstream buffer(temp);
    // Read MC Res line by line (two files opened above)
    // Each line is read word by word into a vector
    std::vector<double> line((std::istream_iterator<double>(buffer)),
    std::istream_iterator<double>());

    resolutions.push_back(line);
  }
  while (std::getline(myfileSF, temp)) {
    std::istringstream buffer(temp);
    std::vector<double> line((std::istream_iterator<double>(buffer)),
    std::istream_iterator<double>());

    scalefactors.push_back(line);
  }

  for( int k = 0; k < scalefactors.size(); k++ ){
    std::cout << "etamin: " << scalefactors[k][0];
    std::cout << "-- etamax: " << scalefactors[k][1];
    std::cout << "-- SF:" << scalefactors[k][3] << std::endl;
  }
  for( int k = 0; k < scalefactors.size(); k++ ){
    std::cout << "etamin: " << scalefactors[k][0];
    std::cout << "-- etamax: " << scalefactors[k][1];
    std::cout << "-- SF: " << scalefactors[k][3] << std::endl;
  }


  // Get pileup weights
  // Warning: It is assumed that the input histograms each
  // have 60 integer bins.
  // It is also assumed that they are at the location below.
  TH1F* h_pileup_mc;
  TH1F* h_pileup_data;
  TFile* pileup_mc = new TFile ("/nfs/dust/cms/user/sonnevej/resolutions_input/pileup_mc.root");
  TFile* pileup_data = new TFile ("/nfs/dust/cms/user/sonnevej/resolutions_input/pileup_data.root");

  h_pileup_mc = (TH1F*) pileup_mc -> Get("PileUp");
  h_pileup_data = (TH1F*) pileup_data -> Get("pileup");
  if(!h_pileup_data)
  {
    h_pileup_data = (TH1F*) pileup_data -> Get("PileUp");
  }
  if(!h_pileup_mc)
  {
    h_pileup_mc = (TH1F*) pileup_mc -> Get("pileup");
  }

  h_pileup_data->Scale(1/h_pileup_data->Integral());
  h_pileup_mc->Scale(1/h_pileup_mc->Integral());
  std::cout << " integral " << std::endl;

  unsigned    bin = 0;
  //unsigned    bin_data_max = 0;
  unsigned    bin_data = 0;
  double mc_pu_weight = 1.;
  double data_pu_weight = 1.;
  double ratio = 1.;
  //double total_data = 0.;
  //double total_mc = 0.;
  for ( int i = 0; i < 61; i++)
  {
    std::cout << " finding bin content " << i << std::endl;
    bin = h_pileup_mc -> FindBin(i);
    bin_data = h_pileup_data -> FindBin(i);
    mc_pu_weight = h_pileup_mc -> GetBinContent(bin);
    data_pu_weight = h_pileup_data -> GetBinContent(bin);

    std::cout << "bin" << bin << ": wt " << mc_pu_weight << "\t,//pu = " << i << "bin content mc= " << std::endl;
    std::cout << "bin" << bin_data << ": wt " << data_pu_weight << "\t,//pu = " << i << "bin content data= " << std::endl;

    ratio = data_pu_weight/mc_pu_weight;
    std::cout << ratio << "\t\t // " << i << "\tPU weight" << std::endl;

    pileup_weight_factors.push_back(ratio);
  }

  pileup_mc -> Close();
  pileup_data -> Close();

  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fChain->SetMakeClass(1);

  //TFile *currentFile = tree->GetCurrentFile();
  TFile* currentFile = ((TChain*)fChain)->GetFile();

  fChain->SetBranchAddress("Njet", &njet, &b_njet);
  fChain->SetBranchAddress("pt_ave", &pt_ave, &b_pt_ave);
  fChain->SetBranchAddress("jet1_pt", &jet1_pt, &b_jet1_pt);
  fChain->SetBranchAddress("jet2_pt", &jet2_pt, &b_jet2_pt);
  fChain->SetBranchAddress("jet3_pt", &jet3_pt, &b_jet3_pt);
  fChain->SetBranchAddress("barreljet_phi", &barreljet_phi, &b_barreljet_phi);
  fChain->SetBranchAddress("barreljet_eta", &barreljet_eta, &b_barreljet_eta);
  fChain->SetBranchAddress("barreljet_pt", &barreljet_pt, &b_barreljet_pt);
  fChain->SetBranchAddress("probejet_phi", &probejet_phi, &b_probejet_phi);
  fChain->SetBranchAddress("probejet_eta", &probejet_eta, &b_probejet_eta);
  fChain->SetBranchAddress("probejet_pt", &probejet_pt, &b_probejet_pt);
  fChain->SetBranchAddress("asymmetry", &asymmetry, &b_asymmetry);
  fChain->SetBranchAddress("alpha", &alpha, &b_alpha);
  fChain->SetBranchAddress("Ngenjet", &ngenjet, &b_ngenjet);
  fChain->SetBranchAddress("gen_pt_ave", &pt_ave, &b_pt_ave);
  fChain->SetBranchAddress("genjet1_pt", &genjet1_pt, &b_genjet1_pt);
  fChain->SetBranchAddress("genjet2_pt", &genjet2_pt, &b_genjet2_pt);
  fChain->SetBranchAddress("genjet3_pt", &genjet3_pt, &b_genjet3_pt);
  fChain->SetBranchAddress("barrelgenjet_phi", &barrelgenjet_phi, &b_barrelgenjet_phi);
  fChain->SetBranchAddress("barrelgenjet_eta", &barrelgenjet_eta, &b_barrelgenjet_eta);
  fChain->SetBranchAddress("barrelgenjet_pt", &barrelgenjet_pt, &b_barrelgenjet_pt);
  fChain->SetBranchAddress("probegenjet_phi", &probegenjet_phi, &b_probegenjet_phi);
  fChain->SetBranchAddress("probegenjet_eta", &probegenjet_eta, &b_probegenjet_eta);
  fChain->SetBranchAddress("probegenjet_pt", &probegenjet_pt, &b_probegenjet_pt);
  fChain->SetBranchAddress("gen_alpha", &gen_alpha, &b_gen_alpha);
  fChain->SetBranchAddress("gen_asymmetry", &gen_asymmetry, &b_gen_asymmetry);
  fChain->SetBranchAddress("weight", &weight, &b_weight);
  fChain->SetBranchAddress("weight_pu", &weight_pu, &b_weight_pu);
  fChain->SetBranchAddress("weight_pu_down", &weight_pu_down, &b_weight_pu_down);
  fChain->SetBranchAddress("weight_pu_up", &weight_pu_up, &b_weight_pu_up);
  fChain->SetBranchAddress("rho", &rho, &b_rho);

}

Bool_t MySelector::Notify(){
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.


  TFile *currentFile = fChain->GetCurrentFile();
  fChain->SetBranchAddress("nPU", &npuIT, &b_npuIT);

  return kTRUE;
}

#endif // #ifdef MySelector_cxx
