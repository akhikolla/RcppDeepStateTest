#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

SEXP BCpi(NumericVector y, NumericMatrix X, double it, double bi, double df, double R2);

TEST(NAM_deepstate_test,BCpi_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/BCpi/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericMatrix X  = RcppDeepState_NumericMatrix();
  qs::c_qsave(X,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/BCpi/inputs/X.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "X values: "<< X << std::endl;
  NumericVector it(1);
  it[0]  = RcppDeepState_double();
  qs::c_qsave(it,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/BCpi/inputs/it.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "it values: "<< it << std::endl;
  NumericVector bi(1);
  bi[0]  = RcppDeepState_double();
  qs::c_qsave(bi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/BCpi/inputs/bi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bi values: "<< bi << std::endl;
  NumericVector df(1);
  df[0]  = RcppDeepState_double();
  qs::c_qsave(df,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/BCpi/inputs/df.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "df values: "<< df << std::endl;
  NumericVector R2(1);
  R2[0]  = RcppDeepState_double();
  qs::c_qsave(R2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/BCpi/inputs/R2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "R2 values: "<< R2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    BCpi(y,X,it[0],bi[0],df[0],R2[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
