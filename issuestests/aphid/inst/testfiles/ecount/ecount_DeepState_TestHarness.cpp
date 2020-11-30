#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector ecount(IntegerVector states, int statearity, IntegerVector residues, int resarity);

TEST(aphid_deepstate_test,ecount_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector states  = RcppDeepState_IntegerVector();
  qs::c_qsave(states,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ecount/inputs/states.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "states values: "<< states << std::endl;
  IntegerVector statearity(1);
  statearity[0]  = RcppDeepState_int();
  qs::c_qsave(statearity,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ecount/inputs/statearity.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "statearity values: "<< statearity << std::endl;
  IntegerVector residues  = RcppDeepState_IntegerVector();
  qs::c_qsave(residues,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ecount/inputs/residues.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "residues values: "<< residues << std::endl;
  IntegerVector resarity(1);
  resarity[0]  = RcppDeepState_int();
  qs::c_qsave(resarity,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ecount/inputs/resarity.qs",
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
