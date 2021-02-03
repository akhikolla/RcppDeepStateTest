#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix hessRcpp(NumericVector par, int T, NumericVector ab, NumericVector wt, NumericMatrix aj1T, NumericMatrix bj1T, NumericMatrix cj1T, int nummet, int itmp, double D, int base);

TEST(equateMultiple_deepstate_test,hessRcpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector par  = RcppDeepState_NumericVector();
  std::string par_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/hessRcpp/AFL_hessRcpp/afl_inputs/" + std::to_string(t) + "_par.qs";
  qs::c_qsave(par,par_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "par values: "<< par << std::endl;
  IntegerVector T(1);
  T[0]  = RcppDeepState_int();
  std::string T_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/hessRcpp/AFL_hessRcpp/afl_inputs/" + std::to_string(t) + "_T.qs";
  qs::c_qsave(T,T_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "T values: "<< T << std::endl;
  NumericVector ab  = RcppDeepState_NumericVector();
  std::string ab_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/hessRcpp/AFL_hessRcpp/afl_inputs/" + std::to_string(t) + "_ab.qs";
  qs::c_qsave(ab,ab_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ab values: "<< ab << std::endl;
  NumericVector wt  = RcppDeepState_NumericVector();
  std::string wt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/hessRcpp/AFL_hessRcpp/afl_inputs/" + std::to_string(t) + "_wt.qs";
  qs::c_qsave(wt,wt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wt values: "<< wt << std::endl;
  NumericMatrix aj1T  = RcppDeepState_NumericMatrix();
  std::string aj1T_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/hessRcpp/AFL_hessRcpp/afl_inputs/" + std::to_string(t) + "_aj1T.qs";
  qs::c_qsave(aj1T,aj1T_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "aj1T values: "<< aj1T << std::endl;
  NumericMatrix bj1T  = RcppDeepState_NumericMatrix();
  std::string bj1T_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/hessRcpp/AFL_hessRcpp/afl_inputs/" + std::to_string(t) + "_bj1T.qs";
  qs::c_qsave(bj1T,bj1T_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bj1T values: "<< bj1T << std::endl;
  NumericMatrix cj1T  = RcppDeepState_NumericMatrix();
  std::string cj1T_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/hessRcpp/AFL_hessRcpp/afl_inputs/" + std::to_string(t) + "_cj1T.qs";
  qs::c_qsave(cj1T,cj1T_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cj1T values: "<< cj1T << std::endl;
  IntegerVector nummet(1);
  nummet[0]  = RcppDeepState_int();
  std::string nummet_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/hessRcpp/AFL_hessRcpp/afl_inputs/" + std::to_string(t) + "_nummet.qs";
  qs::c_qsave(nummet,nummet_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nummet values: "<< nummet << std::endl;
  IntegerVector itmp(1);
  itmp[0]  = RcppDeepState_int();
  std::string itmp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/hessRcpp/AFL_hessRcpp/afl_inputs/" + std::to_string(t) + "_itmp.qs";
  qs::c_qsave(itmp,itmp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "itmp values: "<< itmp << std::endl;
  NumericVector D(1);
  D[0]  = RcppDeepState_double();
  std::string D_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/hessRcpp/AFL_hessRcpp/afl_inputs/" + std::to_string(t) + "_D.qs";
  qs::c_qsave(D,D_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "D values: "<< D << std::endl;
  IntegerVector base(1);
  base[0]  = RcppDeepState_int();
  std::string base_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/equateMultiple/inst/testfiles/hessRcpp/AFL_hessRcpp/afl_inputs/" + std::to_string(t) + "_base.qs";
  qs::c_qsave(base,base_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "base values: "<< base << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    hessRcpp(par,T[0],ab,wt,aj1T,bj1T,cj1T,nummet[0],itmp[0],D[0],base[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
