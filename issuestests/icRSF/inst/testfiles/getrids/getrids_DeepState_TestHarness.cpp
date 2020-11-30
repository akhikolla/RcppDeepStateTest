#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector getrids(NumericVector id, int nsub);

TEST(icRSF_deepstate_test,getrids_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector id  = RcppDeepState_NumericVector();
  qs::c_qsave(id,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/getrids/inputs/id.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "id values: "<< id << std::endl;
  IntegerVector nsub(1);
  nsub[0]  = RcppDeepState_int();
  qs::c_qsave(nsub,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/getrids/inputs/nsub.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nsub values: "<< nsub << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    getrids(id,nsub[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
