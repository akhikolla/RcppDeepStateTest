#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector ecount(IntegerVector states, int statearity, IntegerVector residues, int resarity);

TEST(aphid_deepstate_test,ecount_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector states  = RcppDeepState_IntegerVector();
  std::string states_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ecount/AFL_ecount/afl_inputs/" + std::to_string(t) + "_states.qs";
  qs::c_qsave(states,states_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "states values: "<< states << std::endl;
  IntegerVector statearity(1);
  statearity[0]  = RcppDeepState_int();
  std::string statearity_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ecount/AFL_ecount/afl_inputs/" + std::to_string(t) + "_statearity.qs";
  qs::c_qsave(statearity,statearity_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "statearity values: "<< statearity << std::endl;
  IntegerVector residues  = RcppDeepState_IntegerVector();
  std::string residues_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ecount/AFL_ecount/afl_inputs/" + std::to_string(t) + "_residues.qs";
  qs::c_qsave(residues,residues_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "residues values: "<< residues << std::endl;
  IntegerVector resarity(1);
  resarity[0]  = RcppDeepState_int();
  std::string resarity_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ecount/AFL_ecount/afl_inputs/" + std::to_string(t) + "_resarity.qs";
  qs::c_qsave(resarity,resarity_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "resarity values: "<< resarity << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ecount(states,statearity[0],residues,resarity[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
