#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector lcubestratified(NumericVector prob, NumericMatrix Xspread, NumericMatrix Xbal, IntegerVector integerStrata);

TEST(BalancedSampling_deepstate_test,lcubestratified_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector prob  = RcppDeepState_NumericVector();
  qs::c_qsave(prob,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lcubestratified/inputs/prob.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prob values: "<< prob << std::endl;
  NumericMatrix Xspread  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Xspread,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lcubestratified/inputs/Xspread.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xspread values: "<< Xspread << std::endl;
  NumericMatrix Xbal  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Xbal,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lcubestratified/inputs/Xbal.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xbal values: "<< Xbal << std::endl;
  IntegerVector integerStrata  = RcppDeepState_IntegerVector();
  qs::c_qsave(integerStrata,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lcubestratified/inputs/integerStrata.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "integerStrata values: "<< integerStrata << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    lcubestratified(prob,Xspread,Xbal,integerStrata);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
