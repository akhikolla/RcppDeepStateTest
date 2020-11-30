#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double BDeu_mi(NumericVector x, NumericVector y, int m_x, int m_y, double d);

TEST(BNSL_deepstate_test,BDeu_mi_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/BDeu_mi/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/BDeu_mi/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  IntegerVector m_x(1);
  m_x[0]  = RcppDeepState_int();
  qs::c_qsave(m_x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/BDeu_mi/inputs/m_x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m_x values: "<< m_x << std::endl;
  IntegerVector m_y(1);
  m_y[0]  = RcppDeepState_int();
  qs::c_qsave(m_y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/BDeu_mi/inputs/m_y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m_y values: "<< m_y << std::endl;
  NumericVector d(1);
  d[0]  = RcppDeepState_double();
  qs::c_qsave(d,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BNSL/inst/testfiles/BDeu_mi/inputs/d.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "d values: "<< d << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    BDeu_mi(x,y,m_x[0],m_y[0],d[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
