#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List immer_logdnorm2_derivative(double x, double y, double mu1, double mu2, double var1, double var2, double cov12);

TEST(immer_deepstate_test,immer_logdnorm2_derivative_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x(1);
  x[0]  = RcppDeepState_double();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_logdnorm2_derivative/libFuzzer_immer_logdnorm2_derivative/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y(1);
  y[0]  = RcppDeepState_double();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_logdnorm2_derivative/libFuzzer_immer_logdnorm2_derivative/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector mu1(1);
  mu1[0]  = RcppDeepState_double();
  std::string mu1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_logdnorm2_derivative/libFuzzer_immer_logdnorm2_derivative/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_mu1.qs";
  qs::c_qsave(mu1,mu1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu1 values: "<< mu1 << std::endl;
  NumericVector mu2(1);
  mu2[0]  = RcppDeepState_double();
  std::string mu2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_logdnorm2_derivative/libFuzzer_immer_logdnorm2_derivative/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_mu2.qs";
  qs::c_qsave(mu2,mu2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mu2 values: "<< mu2 << std::endl;
  NumericVector var1(1);
  var1[0]  = RcppDeepState_double();
  std::string var1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_logdnorm2_derivative/libFuzzer_immer_logdnorm2_derivative/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_var1.qs";
  qs::c_qsave(var1,var1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "var1 values: "<< var1 << std::endl;
  NumericVector var2(1);
  var2[0]  = RcppDeepState_double();
  std::string var2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_logdnorm2_derivative/libFuzzer_immer_logdnorm2_derivative/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_var2.qs";
  qs::c_qsave(var2,var2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "var2 values: "<< var2 << std::endl;
  NumericVector cov12(1);
  cov12[0]  = RcppDeepState_double();
  std::string cov12_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/immer/inst/testfiles/immer_logdnorm2_derivative/libFuzzer_immer_logdnorm2_derivative/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cov12.qs";
  qs::c_qsave(cov12,cov12_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cov12 values: "<< cov12 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    immer_logdnorm2_derivative(x[0],y[0],mu1[0],mu2[0],var1[0],var2[0],cov12[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
