#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double icor(int k, int j, int c, NumericVector seq, int M, NumericMatrix csim);

TEST(segmenTier_deepstate_test,icor_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector k(1);
  k[0]  = RcppDeepState_int();
  qs::c_qsave(k,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/icor/inputs/k.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k values: "<< k << std::endl;
  IntegerVector j(1);
  j[0]  = RcppDeepState_int();
  qs::c_qsave(j,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/icor/inputs/j.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "j values: "<< j << std::endl;
  IntegerVector c(1);
  c[0]  = RcppDeepState_int();
  qs::c_qsave(c,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/icor/inputs/c.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "c values: "<< c << std::endl;
  NumericVector seq  = RcppDeepState_NumericVector();
  qs::c_qsave(seq,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/icor/inputs/seq.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seq values: "<< seq << std::endl;
  IntegerVector M(1);
  M[0]  = RcppDeepState_int();
  qs::c_qsave(M,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/icor/inputs/M.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "M values: "<< M << std::endl;
  NumericMatrix csim  = RcppDeepState_NumericMatrix();
  qs::c_qsave(csim,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/segmenTier/inst/testfiles/icor/inputs/csim.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "csim values: "<< csim << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    icor(k[0],j[0],c[0],seq,M[0],csim);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
