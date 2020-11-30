#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector aster_cpp(NumericMatrix matrix, int tree_width, int proc, double s, int n, int ss);

TEST(BNSL_deepstate_test,aster_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix matrix  = RcppDeepState_NumericMatrix();
  qs::c_qsave(matrix,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/aster_cpp/inputs/matrix.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "matrix values: "<< matrix << std::endl;
  IntegerVector tree_width(1);
  tree_width[0]  = RcppDeepState_int();
  qs::c_qsave(tree_width,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/aster_cpp/inputs/tree_width.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tree_width values: "<< tree_width << std::endl;
  IntegerVector proc(1);
  proc[0]  = RcppDeepState_int();
  qs::c_qsave(proc,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/aster_cpp/inputs/proc.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "proc values: "<< proc << std::endl;
  NumericVector s(1);
  s[0]  = RcppDeepState_double();
  qs::c_qsave(s,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/aster_cpp/inputs/s.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "s values: "<< s << std::endl;
  IntegerVector n(1);
  n[0]  = RcppDeepState_int();
  qs::c_qsave(n,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/aster_cpp/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  IntegerVector ss(1);
  ss[0]  = RcppDeepState_int();
  qs::c_qsave(ss,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/aster_cpp/inputs/ss.qs",
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
