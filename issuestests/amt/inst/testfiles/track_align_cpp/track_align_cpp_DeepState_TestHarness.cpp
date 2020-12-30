#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector track_align_cpp(IntegerVector t1, IntegerVector nt, int time_tol, int type);

TEST(amt_deepstate_test,track_align_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector t1  = RcppDeepState_IntegerVector();
  qs::c_qsave(t1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_align_cpp/inputs/t1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t1 values: "<< t1 << std::endl;
  IntegerVector nt  = RcppDeepState_IntegerVector();
  qs::c_qsave(nt,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_align_cpp/inputs/nt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nt values: "<< nt << std::endl;
  IntegerVector time_tol(1);
  time_tol[0]  = RcppDeepState_int();
  qs::c_qsave(time_tol,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_align_cpp/inputs/time_tol.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "time_tol values: "<< time_tol << std::endl;
  IntegerVector type(1);
  type[0]  = RcppDeepState_int();
  qs::c_qsave(type,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_align_cpp/inputs/type.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "type values: "<< type << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    track_align_cpp(t1,nt,time_tol[0],type[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
