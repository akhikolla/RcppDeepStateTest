#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector do_adv_vector_time(NumericVector vvdStart, NumericVector vsdStart, NumericVector vsdTime, NumericVector vvdhStart, NumericVector vvdhTime, NumericVector n, NumericVector f);

TEST(oce_deepstate_test,do_adv_vector_time_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector vvdStart  = RcppDeepState_NumericVector();
  std::string vvdStart_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/AFL_do_adv_vector_time/afl_inputs/" + std::to_string(t) + "_vvdStart.qs";
  qs::c_qsave(vvdStart,vvdStart_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vvdStart values: "<< vvdStart << std::endl;
  NumericVector vsdStart  = RcppDeepState_NumericVector();
  std::string vsdStart_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/AFL_do_adv_vector_time/afl_inputs/" + std::to_string(t) + "_vsdStart.qs";
  qs::c_qsave(vsdStart,vsdStart_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vsdStart values: "<< vsdStart << std::endl;
  NumericVector vsdTime  = RcppDeepState_NumericVector();
  std::string vsdTime_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/AFL_do_adv_vector_time/afl_inputs/" + std::to_string(t) + "_vsdTime.qs";
  qs::c_qsave(vsdTime,vsdTime_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vsdTime values: "<< vsdTime << std::endl;
  NumericVector vvdhStart  = RcppDeepState_NumericVector();
  std::string vvdhStart_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/AFL_do_adv_vector_time/afl_inputs/" + std::to_string(t) + "_vvdhStart.qs";
  qs::c_qsave(vvdhStart,vvdhStart_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vvdhStart values: "<< vvdhStart << std::endl;
  NumericVector vvdhTime  = RcppDeepState_NumericVector();
  std::string vvdhTime_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/AFL_do_adv_vector_time/afl_inputs/" + std::to_string(t) + "_vvdhTime.qs";
  qs::c_qsave(vvdhTime,vvdhTime_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vvdhTime values: "<< vvdhTime << std::endl;
  NumericVector n  = RcppDeepState_NumericVector();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/AFL_do_adv_vector_time/afl_inputs/" + std::to_string(t) + "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector f  = RcppDeepState_NumericVector();
  std::string f_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/AFL_do_adv_vector_time/afl_inputs/" + std::to_string(t) + "_f.qs";
  qs::c_qsave(f,f_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "f values: "<< f << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_adv_vector_time(vvdStart,vsdStart,vsdTime,vvdhStart,vvdhTime,n,f);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
