#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

DataFrame pairSummary(IntegerVector P, IntegerVector I, IntegerVector order);

TEST(hierarchicalSets_deepstate_test,pairSummary_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector P  = RcppDeepState_IntegerVector();
  std::string P_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/pairSummary/AFL_pairSummary/afl_inputs/" + std::to_string(t) + "_P.qs";
  qs::c_qsave(P,P_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  IntegerVector I  = RcppDeepState_IntegerVector();
  std::string I_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/pairSummary/AFL_pairSummary/afl_inputs/" + std::to_string(t) + "_I.qs";
  qs::c_qsave(I,I_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "I values: "<< I << std::endl;
  IntegerVector order  = RcppDeepState_IntegerVector();
  std::string order_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/pairSummary/AFL_pairSummary/afl_inputs/" + std::to_string(t) + "_order.qs";
  qs::c_qsave(order,order_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "order values: "<< order << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pairSummary(P,I,order);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
