#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double Jeffreys_mi(NumericVector x, NumericVector y, int m_x, int m_y);

TEST(BNSL_deepstate_test,Jeffreys_mi_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/Jeffreys_mi/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/Jeffreys_mi/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  std::ofstream m_x_stream;
  int m_x  = RcppDeepState_int();
  m_x_stream.open("/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/Jeffreys_mi/inputs/m_x");
  m_x_stream << m_x;
  std::cout << "m_x values: "<< m_x << std::endl;
  m_x_stream.close();
  std::ofstream m_y_stream;
  int m_y  = RcppDeepState_int();
  m_y_stream.open("/home/akhila/RcppDeepStateTest/BNSL/inst/testfiles/Jeffreys_mi/inputs/m_y");
  m_y_stream << m_y;
  std::cout << "m_y values: "<< m_y << std::endl;
  m_y_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    Jeffreys_mi(x,y,m_x,m_y);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
