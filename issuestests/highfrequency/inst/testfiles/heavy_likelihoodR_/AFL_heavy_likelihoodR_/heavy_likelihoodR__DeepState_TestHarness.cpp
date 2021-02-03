#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List heavy_likelihoodR_(NumericVector h, NumericVector O, NumericVector A, NumericVector B, int TT, int K, int pMax, int qMax, NumericVector data, NumericVector backCast, NumericVector LB, NumericVector UB, NumericVector llRM, NumericVector lls);

TEST(highfrequency_deepstate_test,heavy_likelihoodR__test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector h  = RcppDeepState_NumericVector();
  std::string h_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_h.qs";
  qs::c_qsave(h,h_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  NumericVector O  = RcppDeepState_NumericVector();
  std::string O_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_O.qs";
  qs::c_qsave(O,O_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "O values: "<< O << std::endl;
  NumericVector A  = RcppDeepState_NumericVector();
  std::string A_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_A.qs";
  qs::c_qsave(A,A_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  NumericVector B  = RcppDeepState_NumericVector();
  std::string B_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_B.qs";
  qs::c_qsave(B,B_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B values: "<< B << std::endl;
  IntegerVector TT(1);
  TT[0]  = RcppDeepState_int();
  std::string TT_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_TT.qs";
  qs::c_qsave(TT,TT_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "TT values: "<< TT << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  std::string K_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_K.qs";
  qs::c_qsave(K,K_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  IntegerVector pMax(1);
  pMax[0]  = RcppDeepState_int();
  std::string pMax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_pMax.qs";
  qs::c_qsave(pMax,pMax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pMax values: "<< pMax << std::endl;
  IntegerVector qMax(1);
  qMax[0]  = RcppDeepState_int();
  std::string qMax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_qMax.qs";
  qs::c_qsave(qMax,qMax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "qMax values: "<< qMax << std::endl;
  NumericVector data  = RcppDeepState_NumericVector();
  std::string data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_data.qs";
  qs::c_qsave(data,data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  NumericVector backCast  = RcppDeepState_NumericVector();
  std::string backCast_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_backCast.qs";
  qs::c_qsave(backCast,backCast_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "backCast values: "<< backCast << std::endl;
  NumericVector LB  = RcppDeepState_NumericVector();
  std::string LB_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_LB.qs";
  qs::c_qsave(LB,LB_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "LB values: "<< LB << std::endl;
  NumericVector UB  = RcppDeepState_NumericVector();
  std::string UB_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_UB.qs";
  qs::c_qsave(UB,UB_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "UB values: "<< UB << std::endl;
  NumericVector llRM  = RcppDeepState_NumericVector();
  std::string llRM_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_llRM.qs";
  qs::c_qsave(llRM,llRM_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "llRM values: "<< llRM << std::endl;
  NumericVector lls  = RcppDeepState_NumericVector();
  std::string lls_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/AFL_heavy_likelihoodR_/afl_inputs/" + std::to_string(t) + "_lls.qs";
  qs::c_qsave(lls,lls_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lls values: "<< lls << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    heavy_likelihoodR_(h,O,A,B,TT[0],K[0],pMax[0],qMax[0],data,backCast,LB,UB,llRM,lls);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
