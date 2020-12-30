#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector pcovcc(NumericVector a, NumericVector ap, NumericVector b, NumericVector at, NumericVector atp, NumericVector bt, int na, int nap, int nb, int period);

TEST(highfrequency_deepstate_test,pcovcc_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  qs::c_qsave(a,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/inputs/a.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector ap  = RcppDeepState_NumericVector();
  qs::c_qsave(ap,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/inputs/ap.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ap values: "<< ap << std::endl;
  NumericVector b  = RcppDeepState_NumericVector();
  qs::c_qsave(b,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/inputs/b.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericVector at  = RcppDeepState_NumericVector();
  qs::c_qsave(at,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/inputs/at.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "at values: "<< at << std::endl;
  NumericVector atp  = RcppDeepState_NumericVector();
  qs::c_qsave(atp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/inputs/atp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "atp values: "<< atp << std::endl;
  NumericVector bt  = RcppDeepState_NumericVector();
  qs::c_qsave(bt,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/inputs/bt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bt values: "<< bt << std::endl;
  IntegerVector na(1);
  na[0]  = RcppDeepState_int();
  qs::c_qsave(na,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/inputs/na.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "na values: "<< na << std::endl;
  IntegerVector nap(1);
  nap[0]  = RcppDeepState_int();
  qs::c_qsave(nap,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/inputs/nap.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nap values: "<< nap << std::endl;
  IntegerVector nb(1);
  nb[0]  = RcppDeepState_int();
  qs::c_qsave(nb,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/inputs/nb.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nb values: "<< nb << std::endl;
  IntegerVector period(1);
  period[0]  = RcppDeepState_int();
  qs::c_qsave(period,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/inputs/period.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "period values: "<< period << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pcovcc(a,ap,b,at,atp,bt,na[0],nap[0],nb[0],period[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
