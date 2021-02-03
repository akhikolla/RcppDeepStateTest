#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List setClustering(IntegerVector P, IntegerVector I, CharacterVector setNames, double threshold);

TEST(hierarchicalSets_deepstate_test,setClustering_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector P  = RcppDeepState_IntegerVector();
  std::string P_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/setClustering/AFL_setClustering/afl_inputs/" + std::to_string(t) + "_P.qs";
  qs::c_qsave(P,P_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "P values: "<< P << std::endl;
  IntegerVector I  = RcppDeepState_IntegerVector();
  std::string I_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/setClustering/AFL_setClustering/afl_inputs/" + std::to_string(t) + "_I.qs";
  qs::c_qsave(I,I_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "I values: "<< I << std::endl;
  CharacterVector setNames  = RcppDeepState_CharacterVector();
  std::string setNames_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/setClustering/AFL_setClustering/afl_inputs/" + std::to_string(t) + "_setNames.qs";
  qs::c_qsave(setNames,setNames_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "setNames values: "<< setNames << std::endl;
  NumericVector threshold(1);
  threshold[0]  = RcppDeepState_double();
  std::string threshold_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/setClustering/AFL_setClustering/afl_inputs/" + std::to_string(t) + "_threshold.qs";
  qs::c_qsave(threshold,threshold_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "threshold values: "<< threshold << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    setClustering(P,I,setNames,threshold[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
