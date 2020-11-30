#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerMatrix fftable(NumericMatrix df, int w);

TEST(BNSL_deepstate_test,fftable_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix df  = RcppDeepState_NumericMatrix();
  qs::c_qsave(df,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/fftable/inputs/df.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "df values: "<< df << std::endl;
  IntegerVector w(1);
  w[0]  = RcppDeepState_int();
  qs::c_qsave(w,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/fftable/inputs/w.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    fftable(df,w[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
