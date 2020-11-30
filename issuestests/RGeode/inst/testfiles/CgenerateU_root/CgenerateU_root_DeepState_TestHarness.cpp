#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector CgenerateU_root(NumericVector prodTau, int N, double SIGMAS, NumericMatrix Z);

TEST(RGeode_deepstate_test,CgenerateU_root_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector prodTau  = RcppDeepState_NumericVector();
  qs::c_qsave(prodTau,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateU_root/inputs/prodTau.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "prodTau values: "<< prodTau << std::endl;
  IntegerVector N(1);
  N[0]  = RcppDeepState_int();
  qs::c_qsave(N,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateU_root/inputs/N.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "N values: "<< N << std::endl;
  NumericVector SIGMAS(1);
  SIGMAS[0]  = RcppDeepState_double();
  qs::c_qsave(SIGMAS,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateU_root/inputs/SIGMAS.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SIGMAS values: "<< SIGMAS << std::endl;
  NumericMatrix Z  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Z,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateU_root/inputs/Z.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Z values: "<< Z << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    CgenerateU_root(prodTau,N[0],SIGMAS[0],Z);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
