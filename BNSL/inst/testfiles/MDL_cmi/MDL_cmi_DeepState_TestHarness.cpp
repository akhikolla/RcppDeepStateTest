#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double MDL_cmi(NumericVector x, NumericVector y, NumericVector z, int m_x, int m_y, int m_z);

TEST(BNSL_deepstate_test,MDL_cmi_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akolla/extdata/packages/BNSL/inst/testfiles/MDL_cmi/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akolla/extdata/packages/BNSL/inst/testfiles/MDL_cmi/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  qs::c_qsave(z,"/home/akolla/extdata/packages/BNSL/inst/testfiles/MDL_cmi/inputs/z.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  std::ofstream m_x_stream;
  int m_x  = RcppDeepState_int();
  m_x_stream.open("/home/akolla/extdata/packages/BNSL/inst/testfiles/MDL_cmi/inputs/m_x");
  m_x_stream << m_x;
  std::cout << "m_x values: "<< m_x << std::endl;
  m_x_stream.close();
  std::ofstream m_y_stream;
  int m_y  = RcppDeepState_int();
  m_y_stream.open("/home/akolla/extdata/packages/BNSL/inst/testfiles/MDL_cmi/inputs/m_y");
  m_y_stream << m_y;
  std::cout << "m_y values: "<< m_y << std::endl;
  m_y_stream.close();
  std::ofstream m_z_stream;
  int m_z  = RcppDeepState_int();
  m_z_stream.open("/home/akolla/extdata/packages/BNSL/inst/testfiles/MDL_cmi/inputs/m_z");
  m_z_stream << m_z;
  std::cout << "m_z values: "<< m_z << std::endl;
  m_z_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    MDL_cmi(x,y,z,m_x,m_y,m_z);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
