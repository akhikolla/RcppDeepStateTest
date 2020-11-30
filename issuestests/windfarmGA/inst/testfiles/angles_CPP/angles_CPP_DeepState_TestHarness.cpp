#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector angles_CPP(NumericVector Aa, NumericVector Bb, NumericVector Cc);

TEST(windfarmGA_deepstate_test,angles_CPP_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector Aa  = RcppDeepState_NumericVector();
  qs::c_qsave(Aa,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/windfarmGA/inst/testfiles/angles_CPP/inputs/Aa.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Aa values: "<< Aa << std::endl;
  NumericVector Bb  = RcppDeepState_NumericVector();
  qs::c_qsave(Bb,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/windfarmGA/inst/testfiles/angles_CPP/inputs/Bb.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Bb values: "<< Bb << std::endl;
  NumericVector Cc  = RcppDeepState_NumericVector();
  qs::c_qsave(Cc,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/windfarmGA/inst/testfiles/angles_CPP/inputs/Cc.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Cc values: "<< Cc << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    angles_CPP(Aa,Bb,Cc);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
