#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double kernelEstimator(NumericVector a, NumericVector b, int na, int q, int adj, NumericVector type, NumericVector ab, NumericVector ab2);

TEST(highfrequency_deepstate_test,kernelEstimator_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/AFL_kernelEstimator/afl_inputs/" + std::to_string(t) + "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector b  = RcppDeepState_NumericVector();
  std::string b_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/AFL_kernelEstimator/afl_inputs/" + std::to_string(t) + "_b.qs";
  qs::c_qsave(b,b_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  IntegerVector na(1);
  na[0]  = RcppDeepState_int();
  std::string na_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/AFL_kernelEstimator/afl_inputs/" + std::to_string(t) + "_na.qs";
  qs::c_qsave(na,na_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "na values: "<< na << std::endl;
  IntegerVector q(1);
  q[0]  = RcppDeepState_int();
  std::string q_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/AFL_kernelEstimator/afl_inputs/" + std::to_string(t) + "_q.qs";
  qs::c_qsave(q,q_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "q values: "<< q << std::endl;
  IntegerVector adj(1);
  adj[0]  = RcppDeepState_int();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/AFL_kernelEstimator/afl_inputs/" + std::to_string(t) + "_a.qs";
  std::string adj_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/AFL_kernelEstimator/afl_inputs/" + std::to_string(t) + "_adj.qs";
  qs::c_qsave(adj,adj_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "adj values: "<< adj << std::endl;
  NumericVector type  = RcppDeepState_NumericVector();
  std::string type_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/AFL_kernelEstimator/afl_inputs/" + std::to_string(t) + "_type.qs";
  qs::c_qsave(type,type_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "type values: "<< type << std::endl;
  NumericVector ab  = RcppDeepState_NumericVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/AFL_kernelEstimator/afl_inputs/" + std::to_string(t) + "_a.qs";
  std::string ab_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/AFL_kernelEstimator/afl_inputs/" + std::to_string(t) + "_ab.qs";
  qs::c_qsave(ab,ab_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ab values: "<< ab << std::endl;
  NumericVector ab2  = RcppDeepState_NumericVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/AFL_kernelEstimator/afl_inputs/" + std::to_string(t) + "_a.qs";
  std::string ab_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/AFL_kernelEstimator/afl_inputs/" + std::to_string(t) + "_ab.qs";
  std::string ab2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/kernelEstimator/AFL_kernelEstimator/afl_inputs/" + std::to_string(t) + "_ab2.qs";
  qs::c_qsave(ab2,ab2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ab2 values: "<< ab2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    kernelEstimator(a,b,na[0],q[0],adj[0],type,ab,ab2);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
