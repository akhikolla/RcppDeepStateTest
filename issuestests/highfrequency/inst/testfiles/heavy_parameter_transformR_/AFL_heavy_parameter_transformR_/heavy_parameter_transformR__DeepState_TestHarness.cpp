#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List heavy_parameter_transformR_(NumericVector parameters, int K, IntegerVector p, IntegerVector q, NumericVector O, NumericVector A, NumericVector B, IntegerVector pMax1, IntegerVector qMax1);

TEST(highfrequency_deepstate_test,heavy_parameter_transformR__test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector parameters  = RcppDeepState_NumericVector();
  std::string parameters_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/AFL_heavy_parameter_transformR_/afl_inputs/" + std::to_string(t) + "_parameters.qs";
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/AFL_heavy_parameter_transformR_/afl_inputs/" + std::to_string(t) + "_p.qs";
  qs::c_qsave(parameters,parameters_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "parameters values: "<< parameters << std::endl;
  IntegerVector K(1);
  K[0]  = RcppDeepState_int();
  std::string K_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/AFL_heavy_parameter_transformR_/afl_inputs/" + std::to_string(t) + "_K.qs";
  qs::c_qsave(K,K_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "K values: "<< K << std::endl;
  IntegerVector p  = RcppDeepState_IntegerVector();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/AFL_heavy_parameter_transformR_/afl_inputs/" + std::to_string(t) + "_p.qs";
  qs::c_qsave(p,p_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  IntegerVector q  = RcppDeepState_IntegerVector();
  std::string q_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/AFL_heavy_parameter_transformR_/afl_inputs/" + std::to_string(t) + "_q.qs";
  qs::c_qsave(q,q_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "q values: "<< q << std::endl;
  NumericVector O  = RcppDeepState_NumericVector();
  std::string O_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/AFL_heavy_parameter_transformR_/afl_inputs/" + std::to_string(t) + "_O.qs";
  qs::c_qsave(O,O_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "O values: "<< O << std::endl;
  NumericVector A  = RcppDeepState_NumericVector();
  std::string A_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/AFL_heavy_parameter_transformR_/afl_inputs/" + std::to_string(t) + "_A.qs";
  qs::c_qsave(A,A_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "A values: "<< A << std::endl;
  NumericVector B  = RcppDeepState_NumericVector();
  std::string B_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/AFL_heavy_parameter_transformR_/afl_inputs/" + std::to_string(t) + "_B.qs";
  qs::c_qsave(B,B_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B values: "<< B << std::endl;
  IntegerVector pMax1  = RcppDeepState_IntegerVector();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/AFL_heavy_parameter_transformR_/afl_inputs/" + std::to_string(t) + "_p.qs";
  std::string pMax1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/AFL_heavy_parameter_transformR_/afl_inputs/" + std::to_string(t) + "_pMax1.qs";
  qs::c_qsave(pMax1,pMax1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pMax1 values: "<< pMax1 << std::endl;
  IntegerVector qMax1  = RcppDeepState_IntegerVector();
  std::string q_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/AFL_heavy_parameter_transformR_/afl_inputs/" + std::to_string(t) + "_q.qs";
  std::string qMax1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/heavy_parameter_transformR_/AFL_heavy_parameter_transformR_/afl_inputs/" + std::to_string(t) + "_qMax1.qs";
  qs::c_qsave(qMax1,qMax1_t,
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
