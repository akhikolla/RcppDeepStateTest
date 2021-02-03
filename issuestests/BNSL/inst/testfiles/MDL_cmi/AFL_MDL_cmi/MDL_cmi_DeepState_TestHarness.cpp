#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double MDL_cmi(NumericVector x, NumericVector y, NumericVector z, int m_x, int m_y, int m_z);

TEST(BNSL_deepstate_test,MDL_cmi_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/MDL_cmi/AFL_MDL_cmi/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/MDL_cmi/AFL_MDL_cmi/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/MDL_cmi/AFL_MDL_cmi/afl_inputs/" + std::to_string(t) + "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  IntegerVector m_x(1);
  m_x[0]  = RcppDeepState_int();
  std::string m_x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/MDL_cmi/AFL_MDL_cmi/afl_inputs/" + std::to_string(t) + "_m_x.qs";
  qs::c_qsave(m_x,m_x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m_x values: "<< m_x << std::endl;
  IntegerVector m_y(1);
  m_y[0]  = RcppDeepState_int();
  std::string m_y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/MDL_cmi/AFL_MDL_cmi/afl_inputs/" + std::to_string(t) + "_m_y.qs";
  qs::c_qsave(m_y,m_y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m_y values: "<< m_y << std::endl;
  IntegerVector m_z(1);
  m_z[0]  = RcppDeepState_int();
  std::string m_z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/MDL_cmi/AFL_MDL_cmi/afl_inputs/" + std::to_string(t) + "_m_z.qs";
  qs::c_qsave(m_z,m_z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m_z values: "<< m_z << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    MDL_cmi(x,y,z,m_x[0],m_y[0],m_z[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
