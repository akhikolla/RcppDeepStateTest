#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double BDeu_cmi(NumericVector x, NumericVector y, NumericVector z, int m_x, int m_y, int m_z, double d);

TEST(BNSL_deepstate_test,BDeu_cmi_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/BDeu_cmi/libFuzzer_BDeu_cmi/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/BDeu_cmi/libFuzzer_BDeu_cmi/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/BDeu_cmi/libFuzzer_BDeu_cmi/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  IntegerVector m_x(1);
  m_x[0]  = RcppDeepState_int();
  std::string m_x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/BDeu_cmi/libFuzzer_BDeu_cmi/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_m_x.qs";
  qs::c_qsave(m_x,m_x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m_x values: "<< m_x << std::endl;
  IntegerVector m_y(1);
  m_y[0]  = RcppDeepState_int();
  std::string m_y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/BDeu_cmi/libFuzzer_BDeu_cmi/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_m_y.qs";
  qs::c_qsave(m_y,m_y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m_y values: "<< m_y << std::endl;
  IntegerVector m_z(1);
  m_z[0]  = RcppDeepState_int();
  std::string m_z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/BDeu_cmi/libFuzzer_BDeu_cmi/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_m_z.qs";
  qs::c_qsave(m_z,m_z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m_z values: "<< m_z << std::endl;
  NumericVector d(1);
  d[0]  = RcppDeepState_double();
  std::string d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/BDeu_cmi/libFuzzer_BDeu_cmi/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_d.qs";
  qs::c_qsave(d,d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "d values: "<< d << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    BDeu_cmi(x,y,z,m_x[0],m_y[0],m_z[0],d[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
