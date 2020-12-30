#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void SAMP(NumericMatrix C, NumericVector g, NumericVector r, int N, double Ve);

TEST(NAM_deepstate_test,SAMP_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix C  = RcppDeepState_NumericMatrix();
  qs::c_qsave(C,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP/inputs/C.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "C values: "<< C << std::endl;
  NumericVector g  = RcppDeepState_NumericVector();
  qs::c_qsave(g,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP/inputs/g.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "g values: "<< g << std::endl;
  NumericVector r  = RcppDeepState_NumericVector();
  qs::c_qsave(r,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP/inputs/r.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "r values: "<< r << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  qs::c_qsave(N,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP/inputs/N.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  NumericVector Ve(1);
  Ve[0]  = RcppDeepState_double();
  qs::c_qsave(Ve,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SAMP/inputs/Ve.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Ve values: "<< Ve << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    SAMP(C,g,r,N[0],Ve[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
