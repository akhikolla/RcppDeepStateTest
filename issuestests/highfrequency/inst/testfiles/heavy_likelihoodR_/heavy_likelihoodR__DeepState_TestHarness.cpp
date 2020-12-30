#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List heavy_likelihoodR_(NumericVector h, NumericVector O, NumericVector A, NumericVector B, int TT, int K, int pMax, int qMax, NumericVector data, NumericVector backCast, NumericVector LB, NumericVector UB, NumericVector llRM, NumericVector lls);

TEST(highfrequency_deepstate_test,heavy_likelihoodR__test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector h  = RcppDeepState_NumericVector();
  qs::c_qsave(h,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/h.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  NumericVector O  = RcppDeepState_NumericVector();
  qs::c_qsave(O,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/O.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "O values: "<< O << std::endl;
  NumericVector A  = RcppDeepState_NumericVector();
  qs::c_qsave(A,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/A.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  NumericVector B  = RcppDeepState_NumericVector();
  qs::c_qsave(B,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/B.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B values: "<< B << std::endl;
  IntegerVector TT(1);
  TT[0]  = RcppDeepState_int();
  qs::c_qsave(TT,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/TT.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "TT values: "<< TT << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  qs::c_qsave(K,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/K.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  IntegerVector pMax(1);
  pMax[0]  = RcppDeepState_int();
  qs::c_qsave(pMax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/pMax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pMax values: "<< pMax << std::endl;
  IntegerVector qMax(1);
  qMax[0]  = RcppDeepState_int();
  qs::c_qsave(qMax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/qMax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "qMax values: "<< qMax << std::endl;
  NumericVector data  = RcppDeepState_NumericVector();
  qs::c_qsave(data,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/data.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  NumericVector backCast  = RcppDeepState_NumericVector();
  qs::c_qsave(backCast,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/backCast.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "backCast values: "<< backCast << std::endl;
  NumericVector LB  = RcppDeepState_NumericVector();
  qs::c_qsave(LB,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/LB.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "LB values: "<< LB << std::endl;
  NumericVector UB  = RcppDeepState_NumericVector();
  qs::c_qsave(UB,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/UB.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "UB values: "<< UB << std::endl;
  NumericVector llRM  = RcppDeepState_NumericVector();
  qs::c_qsave(llRM,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/llRM.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "llRM values: "<< llRM << std::endl;
  NumericVector lls  = RcppDeepState_NumericVector();
  qs::c_qsave(lls,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_likelihoodR_/inputs/lls.qs",
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
