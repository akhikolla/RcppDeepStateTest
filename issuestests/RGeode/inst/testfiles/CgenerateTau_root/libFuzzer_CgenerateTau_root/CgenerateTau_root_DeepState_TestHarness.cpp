#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector CgenerateTau_root(NumericVector U, NumericVector t, double a, int d);

TEST(RGeode_deepstate_test,CgenerateTau_root_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector U  = RcppDeepState_NumericVector();
  std::string U_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateTau_root/libFuzzer_CgenerateTau_root/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_U.qs";
  qs::c_qsave(U,U_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "U values: "<< U << std::endl;
  NumericVector t  = RcppDeepState_NumericVector();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateTau_root/libFuzzer_CgenerateTau_root/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_t.qs";
  qs::c_qsave(t,t_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  NumericVector a(1);
  a[0]  = RcppDeepState_double();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateTau_root/libFuzzer_CgenerateTau_root/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  IntegerVector d(1);
  d[0]  = RcppDeepState_int();
  std::string d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RGeode/inst/testfiles/CgenerateTau_root/libFuzzer_CgenerateTau_root/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_d.qs";
  qs::c_qsave(d,d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "d values: "<< d << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    CgenerateTau_root(U,t,a[0],d[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
