#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector track_align_cpp(IntegerVector t1, IntegerVector nt, int time_tol, int type);

TEST(amt_deepstate_test,track_align_cpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector t1  = RcppDeepState_IntegerVector();
  std::string t1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_align_cpp/libFuzzer_track_align_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_t1.qs";
  qs::c_qsave(t1,t1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t1 values: "<< t1 << std::endl;
  IntegerVector nt  = RcppDeepState_IntegerVector();
  std::string nt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_align_cpp/libFuzzer_track_align_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nt.qs";
  qs::c_qsave(nt,nt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nt values: "<< nt << std::endl;
  IntegerVector time_tol(1);
  time_tol[0]  = RcppDeepState_int();
  std::string time_tol_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_align_cpp/libFuzzer_track_align_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_time_tol.qs";
  qs::c_qsave(time_tol,time_tol_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "time_tol values: "<< time_tol << std::endl;
  IntegerVector type(1);
  type[0]  = RcppDeepState_int();
  std::string type_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_align_cpp/libFuzzer_track_align_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_type.qs";
  qs::c_qsave(type,type_t,
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
