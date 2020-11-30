#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double rv(NumericVector a, NumericVector b, int na, int period, NumericVector tmpa, NumericVector tmpb, int tmpna);

TEST(highfrequency_deepstate_test,rv_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  qs::c_qsave(a,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/inputs/a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector b  = RcppDeepState_NumericVector();
  qs::c_qsave(b,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/inputs/b.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  IntegerVector na(1);
  na[0]  = RcppDeepState_int();
  qs::c_qsave(na,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/inputs/na.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "na values: "<< na << std::endl;
  IntegerVector period(1);
  period[0]  = RcppDeepState_int();
  qs::c_qsave(period,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/inputs/period.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "period values: "<< period << std::endl;
  NumericVector tmpa  = RcppDeepState_NumericVector();
  qs::c_qsave(tmpa,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/inputs/tmpa.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tmpa values: "<< tmpa << std::endl;
  NumericVector tmpb  = RcppDeepState_NumericVector();
  qs::c_qsave(tmpb,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/inputs/tmpb.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tmpb values: "<< tmpb << std::endl;
  IntegerVector tmpna(1);
  tmpna[0]  = RcppDeepState_int();
  qs::c_qsave(tmpna,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/rv/inputs/tmpna.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tmpna values: "<< tmpna << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    rv(a,b,na[0],period[0],tmpa,tmpb,tmpna[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
