#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double ldnbinom(double y, double E, double a, double b);

TEST(SpatialEpi_deepstate_test,ldnbinom_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector y(1);
  y[0]  = RcppDeepState_double();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/ldnbinom/libFuzzer_ldnbinom/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector E(1);
  E[0]  = RcppDeepState_double();
  std::string E_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/ldnbinom/libFuzzer_ldnbinom/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_E.qs";
  qs::c_qsave(E,E_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "E values: "<< E << std::endl;
  NumericVector a(1);
  a[0]  = RcppDeepState_double();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/ldnbinom/libFuzzer_ldnbinom/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector b(1);
  b[0]  = RcppDeepState_double();
  std::string b_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/ldnbinom/libFuzzer_ldnbinom/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_b.qs";
  qs::c_qsave(b,b_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ldnbinom(y[0],E[0],a[0],b[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
