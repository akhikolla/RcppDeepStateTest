#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector splitt_var(NumericVector df, NumericVector phi, NumericVector lmd);

TEST(dng_deepstate_test,splitt_var_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector df  = RcppDeepState_NumericVector();
  qs::c_qsave(df,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/splitt_var/inputs/df.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "df values: "<< df << std::endl;
  NumericVector phi  = RcppDeepState_NumericVector();
  qs::c_qsave(phi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/splitt_var/inputs/phi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi values: "<< phi << std::endl;
  NumericVector lmd  = RcppDeepState_NumericVector();
  qs::c_qsave(lmd,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/dng/inst/testfiles/splitt_var/inputs/lmd.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lmd values: "<< lmd << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    splitt_var(df,phi,lmd);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
