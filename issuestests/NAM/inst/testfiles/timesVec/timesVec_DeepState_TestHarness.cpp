#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix timesVec(NumericVector aa, NumericVector h, NumericMatrix bb, int q);

TEST(NAM_deepstate_test,timesVec_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector aa  = RcppDeepState_NumericVector();
  qs::c_qsave(aa,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesVec/inputs/aa.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "aa values: "<< aa << std::endl;
  NumericVector h  = RcppDeepState_NumericVector();
  qs::c_qsave(h,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesVec/inputs/h.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  NumericMatrix bb  = RcppDeepState_NumericMatrix();
  qs::c_qsave(bb,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesVec/inputs/bb.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bb values: "<< bb << std::endl;
  IntegerVector q(1);
  q[0]  = RcppDeepState_int();
  qs::c_qsave(q,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesVec/inputs/q.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "q values: "<< q << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    timesVec(aa,h,bb,q[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
