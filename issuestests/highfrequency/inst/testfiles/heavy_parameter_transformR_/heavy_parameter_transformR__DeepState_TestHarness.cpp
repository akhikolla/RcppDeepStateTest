#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List heavy_parameter_transformR_(NumericVector parameters, int K, IntegerVector p, IntegerVector q, NumericVector O, NumericVector A, NumericVector B, IntegerVector pMax1, IntegerVector qMax1);

TEST(highfrequency_deepstate_test,heavy_parameter_transformR__test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector parameters  = RcppDeepState_NumericVector();
  qs::c_qsave(parameters,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/inputs/parameters.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "parameters values: "<< parameters << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  qs::c_qsave(K,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/inputs/K.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  IntegerVector p  = RcppDeepState_IntegerVector();
  qs::c_qsave(p,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/inputs/p.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  IntegerVector q  = RcppDeepState_IntegerVector();
  qs::c_qsave(q,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/inputs/q.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "q values: "<< q << std::endl;
  NumericVector O  = RcppDeepState_NumericVector();
  qs::c_qsave(O,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/inputs/O.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "O values: "<< O << std::endl;
  NumericVector A  = RcppDeepState_NumericVector();
  qs::c_qsave(A,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/inputs/A.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  NumericVector B  = RcppDeepState_NumericVector();
  qs::c_qsave(B,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/inputs/B.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B values: "<< B << std::endl;
  IntegerVector pMax1  = RcppDeepState_IntegerVector();
  qs::c_qsave(pMax1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/inputs/pMax1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pMax1 values: "<< pMax1 << std::endl;
  IntegerVector qMax1  = RcppDeepState_IntegerVector();
  qs::c_qsave(qMax1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/inputs/qMax1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "qMax1 values: "<< qMax1 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    heavy_parameter_transformR_(parameters,K[0],p,q,O,A,B,pMax1,qMax1);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
