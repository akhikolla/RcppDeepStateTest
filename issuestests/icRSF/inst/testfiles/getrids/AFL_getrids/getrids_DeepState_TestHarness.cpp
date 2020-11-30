#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector getrids(NumericVector id, int nsub);

TEST(icRSF_deepstate_test,getrids_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector id  = RcppDeepState_NumericVector();
  std::string id_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/getrids/AFL_getrids/afl_inputs/" + std::to_string(t) + "_id.qs";
  qs::c_qsave(id,id_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "id values: "<< id << std::endl;
  IntegerVector nsub(1);
  nsub[0]  = RcppDeepState_int();
  std::string nsub_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/getrids/AFL_getrids/afl_inputs/" + std::to_string(t) + "_nsub.qs";
  qs::c_qsave(nsub,nsub_t,
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
