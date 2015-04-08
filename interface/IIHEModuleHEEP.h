#ifndef UserCode_IIHETree_IIHEModuleHEEP_h
#define UserCode_IIHETree_IIHEModuleHEEP_h

class HEEPCut_isolEMHadDepth1 ;
class HEEPCut_dxyFirstPV ;
class HEEPCutCollection ;
class HEEPParameter ;

#include "UserCode/IIHETree/interface/IIHEModule.h"
#include "UserCode/IIHETree/interface/HEEPCut.h"

// class decleration
class IIHEModuleHEEP : public IIHEModule {
private:
  std::vector<HEEPParameter*> parameters_ ;
  void addHEEPParameter(int, std::string, std::string, float) ;
  
  bool storeHEEP41_    ;
  bool storeHEEP50_50_ ;
  bool storeHEEP50_25_ ;
  bool storeHEEP50_    ;
  bool storeHEEP51_    ;
  
  double rho_ ;
  
  HEEPCut_isolEMHadDepth1* cut_41_isolEMHadDepth1_ ;
  HEEPCut_dxyFirstPV*      cut_41_dxyFirstPV_      ;
  HEEPCutCollection* HEEPCutflow_41_acceptance_ ;
  HEEPCutCollection* HEEPCutflow_41_ID_         ;
  HEEPCutCollection* HEEPCutflow_41_isolation_  ;
  HEEPCutCollection* HEEPCutflow_41_total_      ;
  
  HEEPCut_isolEMHadDepth1* cut_50_50ns_isolEMHadDepth1_ ;
  HEEPCut_dxyFirstPV*      cut_50_50ns_dxyFirstPV_      ;
  HEEPCutCollection* HEEPCutflow_50_50ns_acceptance_ ;
  HEEPCutCollection* HEEPCutflow_50_50ns_ID_         ;
  HEEPCutCollection* HEEPCutflow_50_50ns_isolation_  ;
  HEEPCutCollection* HEEPCutflow_50_50ns_total_      ;
  
  HEEPCut_isolEMHadDepth1* cut_50_25ns_isolEMHadDepth1_ ;
  HEEPCut_dxyFirstPV*      cut_50_25ns_dxyFirstPV_      ;
  HEEPCutCollection* HEEPCutflow_50_25ns_acceptance_ ;
  HEEPCutCollection* HEEPCutflow_50_25ns_ID_         ;
  HEEPCutCollection* HEEPCutflow_50_25ns_isolation_  ;
  HEEPCutCollection* HEEPCutflow_50_25ns_total_      ;
  
  HEEPCut_isolEMHadDepth1* cut_50_isolEMHadDepth1_ ;
  HEEPCut_dxyFirstPV*      cut_50_dxyFirstPV_      ;
  HEEPCutCollection* HEEPCutflow_50_acceptance_ ;
  HEEPCutCollection* HEEPCutflow_50_ID_         ;
  HEEPCutCollection* HEEPCutflow_50_isolation_  ;
  HEEPCutCollection* HEEPCutflow_50_total_      ;
  
  HEEPCut_isolEMHadDepth1* cut_51_isolEMHadDepth1_ ;
  HEEPCut_dxyFirstPV*      cut_51_dxyFirstPV_      ;
  HEEPCutCollection* HEEPCutflow_51_acceptance_ ;
  HEEPCutCollection* HEEPCutflow_51_ID_         ;
  HEEPCutCollection* HEEPCutflow_51_isolation_  ;
  HEEPCutCollection* HEEPCutflow_51_total_      ;
  
  // +/- first, plane second
  float ES_OX_[2][2] ;
  float ES_OY_[2][2] ;
  float ES_OZ_[2][2] ;
  
  std::vector<std::string> triggersForMatching_ ;
public:
  explicit IIHEModuleHEEP(const edm::ParameterSet& iConfig);
  ~IIHEModuleHEEP();
  
  void   pubBeginJob(){   beginJob() ; } ;
  void pubBeginEvent(){ beginEvent() ; } ;
  void   pubEndEvent(){   endEvent() ; } ;
  virtual void pubAnalyze(const edm::Event& iEvent, const edm::EventSetup& iSetup){ analyze(iEvent, iSetup) ; } ;
  
  virtual void beginEvent() ;
  virtual void endEvent() ;
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  virtual void beginRun(edm::Run const&, edm::EventSetup const&);
  
  std::vector<HEEPCutCollection*> HEEPCutflows_ ;
};

#endif
