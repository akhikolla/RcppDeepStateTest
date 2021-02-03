#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector computeMSPEcpp(NumericVector X, NumericVector coef, int h, IntegerVector t, int type, double trimLo, double trimUp);

TEST(forecastSNSTS_deepstate_test,computeMSPEcpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector X  = RcppDeepState_NumericVector();
  std::string X_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/AFL_computeMSPEcpp/afl_inputs/" + std::to_string(t) + "_X.qs";
  qs::c_qsave(X,X_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector coef  = RcppDeepState_NumericVector();
  std::string coef_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/AFL_computeMSPEcpp/afl_inputs/" + std::to_string(t) + "_coef.qs";
  qs::c_qsave(coef,coef_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "coef values: "<< coef << std::endl;
  IntegerVector h(1);
  h[0]  = RcppDeepState_int();
  std::string h_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/AFL_computeMSPEcpp/afl_inputs/" + std::to_string(t) + "_h.qs";
  qs::c_qsave(h,h_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  IntegerVector t  = RcppDeepState_IntegerVector();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/AFL_computeMSPEcpp/afl_inputs/" + std::to_string(t) + "_t.qs";
  qs::c_qsave(t,t_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  IntegerVector type(1);
  type[0]  = RcppDeepState_int();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/AFL_computeMSPEcpp/afl_inputs/" + std::to_string(t) + "_t.qs";
  std::string type_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/AFL_computeMSPEcpp/afl_inputs/" + std::to_string(t) + "_type.qs";
  qs::c_qsave(type,type_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "type values: "<< type << std::endl;
  NumericVector trimLo(1);
  trimLo[0]  = RcppDeepState_double();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/AFL_computeMSPEcpp/afl_inputs/" + std::to_string(t) + "_t.qs";
  std::string trimLo_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/AFL_computeMSPEcpp/afl_inputs/" + std::to_string(t) + "_trimLo.qs";
  qs::c_qsave(trimLo,trimLo_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "trimLo values: "<< trimLo << std::endl;
  NumericVector trimUp(1);
  trimUp[0]  = RcppDeepState_double();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/AFL_computeMSPEcpp/afl_inputs/" + std::to_string(t) + "_t.qs";
  std::string trimUp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/forecastSNSTS/inst/testfiles/computeMSPEcpp/AFL_computeMSPEcpp/afl_inputs/" + std::to_string(t) + "_trimUp.qs";
  qs::c_qsave(trimUp,trimUp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "trimUp values: "<< trimUp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    computeMSPEcpp(X,coef,h[0],t,type[0],trimLo[0],trimUp[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
