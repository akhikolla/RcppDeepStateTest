#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector lcubelandingphase(NumericVector prob, NumericVector probflight, NumericMatrix Xspread, NumericMatrix Xbal);

TEST(BalancedSampling_deepstate_test,lcubelandingphase_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector prob  = RcppDeepState_NumericVector();
  qs::c_qsave(prob,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lcubelandingphase/inputs/prob.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prob values: "<< prob << std::endl;
  NumericVector probflight  = RcppDeepState_NumericVector();
  qs::c_qsave(probflight,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lcubelandingphase/inputs/probflight.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "probflight values: "<< probflight << std::endl;
  NumericMatrix Xspread  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Xspread,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lcubelandingphase/inputs/Xspread.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xspread values: "<< Xspread << std::endl;
  NumericMatrix Xbal  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Xbal,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BalancedSampling/inst/testfiles/lcubelandingphase/inputs/Xbal.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xbal values: "<< Xbal << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    lcubelandingphase(prob,probflight,Xspread,Xbal);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
