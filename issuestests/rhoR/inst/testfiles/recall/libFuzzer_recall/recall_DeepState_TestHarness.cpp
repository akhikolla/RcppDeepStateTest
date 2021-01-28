#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double recall(double kappa, double BR, double P);

TEST(rhoR_deepstate_test,recall_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector kappa(1);
  kappa[0]  = RcppDeepState_double();
  std::string kappa_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/recall/libFuzzer_recall/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_kappa.qs";
  qs::c_qsave(kappa,kappa_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kappa values: "<< kappa << std::endl;
  NumericVector BR(1);
  BR[0]  = RcppDeepState_double();
  std::string BR_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/recall/libFuzzer_recall/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_BR.qs";
  qs::c_qsave(BR,BR_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "BR values: "<< BR << std::endl;
  NumericVector P(1);
  P[0]  = RcppDeepState_double();
  std::string P_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/recall/libFuzzer_recall/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_P.qs";
  qs::c_qsave(P,P_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    recall(kappa[0],BR[0],P[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
