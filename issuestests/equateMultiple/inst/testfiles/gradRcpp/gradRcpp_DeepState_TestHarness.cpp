#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector gradRcpp(NumericVector par, int T, NumericVector ab, NumericVector wt, NumericMatrix aj1T, NumericMatrix bj1T, NumericMatrix cj1T, int nummet, int itmp, double D, int base);

TEST(equateMultiple_deepstate_test,gradRcpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector par  = RcppDeepState_NumericVector();
  qs::c_qsave(par,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/gradRcpp/inputs/par.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "par values: "<< par << std::endl;
  IntegerVector T(1);
  T[0]  = RcppDeepState_int();
  qs::c_qsave(T,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/gradRcpp/inputs/T.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "T values: "<< T << std::endl;
  NumericVector ab  = RcppDeepState_NumericVector();
  qs::c_qsave(ab,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/gradRcpp/inputs/ab.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ab values: "<< ab << std::endl;
  NumericVector wt  = RcppDeepState_NumericVector();
  qs::c_qsave(wt,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/gradRcpp/inputs/wt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wt values: "<< wt << std::endl;
  NumericMatrix aj1T  = RcppDeepState_NumericMatrix();
  qs::c_qsave(aj1T,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/gradRcpp/inputs/aj1T.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "aj1T values: "<< aj1T << std::endl;
  NumericMatrix bj1T  = RcppDeepState_NumericMatrix();
  qs::c_qsave(bj1T,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/gradRcpp/inputs/bj1T.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bj1T values: "<< bj1T << std::endl;
  NumericMatrix cj1T  = RcppDeepState_NumericMatrix();
  qs::c_qsave(cj1T,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/gradRcpp/inputs/cj1T.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cj1T values: "<< cj1T << std::endl;
  IntegerVector nummet(1);
  nummet[0]  = RcppDeepState_int();
  qs::c_qsave(nummet,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/gradRcpp/inputs/nummet.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nummet values: "<< nummet << std::endl;
  IntegerVector itmp(1);
  itmp[0]  = RcppDeepState_int();
  qs::c_qsave(itmp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/gradRcpp/inputs/itmp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "itmp values: "<< itmp << std::endl;
  NumericVector D(1);
  D[0]  = RcppDeepState_double();
  qs::c_qsave(D,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/gradRcpp/inputs/D.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "D values: "<< D << std::endl;
  IntegerVector base(1);
  base[0]  = RcppDeepState_int();
  qs::c_qsave(base,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/gradRcpp/inputs/base.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "base values: "<< base << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gradRcpp(par,T[0],ab,wt,aj1T,bj1T,cj1T,nummet[0],itmp[0],D[0],base[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
