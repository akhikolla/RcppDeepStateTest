#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double recall(double kappa, double BR, double P);

TEST(rhoR_deepstate_test,recall_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector kappa(1);
  kappa[0]  = RcppDeepState_double();
  qs::c_qsave(kappa,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/recall/inputs/kappa.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "kappa values: "<< kappa << std::endl;
  NumericVector BR(1);
  BR[0]  = RcppDeepState_double();
  qs::c_qsave(BR,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/recall/inputs/BR.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "BR values: "<< BR << std::endl;
  NumericVector P(1);
  P[0]  = RcppDeepState_double();
  qs::c_qsave(P,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/recall/inputs/P.qs",
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
