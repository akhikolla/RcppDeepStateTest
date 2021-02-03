#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector aster_cpp(NumericMatrix matrix, int tree_width, int proc, double s, int n, int ss);

TEST(BNSL_deepstate_test,aster_cpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix matrix  = RcppDeepState_NumericMatrix();
  std::string matrix_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/aster_cpp/AFL_aster_cpp/afl_inputs/" + std::to_string(t) + "_matrix.qs";
  qs::c_qsave(matrix,matrix_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "matrix values: "<< matrix << std::endl;
  IntegerVector tree_width(1);
  tree_width[0]  = RcppDeepState_int();
  std::string tree_width_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/aster_cpp/AFL_aster_cpp/afl_inputs/" + std::to_string(t) + "_tree_width.qs";
  qs::c_qsave(tree_width,tree_width_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tree_width values: "<< tree_width << std::endl;
  IntegerVector proc(1);
  proc[0]  = RcppDeepState_int();
  std::string proc_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/aster_cpp/AFL_aster_cpp/afl_inputs/" + std::to_string(t) + "_proc.qs";
  qs::c_qsave(proc,proc_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "proc values: "<< proc << std::endl;
  NumericVector s(1);
  s[0]  = RcppDeepState_double();
  std::string s_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/aster_cpp/AFL_aster_cpp/afl_inputs/" + std::to_string(t) + "_s.qs";
  qs::c_qsave(s,s_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "s values: "<< s << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/aster_cpp/AFL_aster_cpp/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  IntegerVector ss(1);
  ss[0]  = RcppDeepState_int();
  std::string s_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/aster_cpp/AFL_aster_cpp/afl_inputs/" + std::to_string(t) + "_s.qs";
  std::string ss_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/aster_cpp/AFL_aster_cpp/afl_inputs/" + std::to_string(t) + "_ss.qs";
  qs::c_qsave(ss,ss_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ss values: "<< ss << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    aster_cpp(matrix,tree_width[0],proc[0],s[0],n[0],ss[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
