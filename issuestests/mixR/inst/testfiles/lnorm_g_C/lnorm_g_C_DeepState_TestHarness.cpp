#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List lnorm_g_C(NumericMatrix data, NumericVector pi, NumericVector mulog, NumericVector sdlog, int max_iter, double tol);

TEST(mixR_deepstate_test,lnorm_g_C_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix data  = RcppDeepState_NumericMatrix();
  qs::c_qsave(data,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/lnorm_g_C/inputs/data.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  NumericVector pi  = RcppDeepState_NumericVector();
  qs::c_qsave(pi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/lnorm_g_C/inputs/pi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pi values: "<< pi << std::endl;
  NumericVector mulog  = RcppDeepState_NumericVector();
  qs::c_qsave(mulog,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/lnorm_g_C/inputs/mulog.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "mulog values: "<< mulog << std::endl;
  NumericVector sdlog  = RcppDeepState_NumericVector();
  qs::c_qsave(sdlog,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/lnorm_g_C/inputs/sdlog.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sdlog values: "<< sdlog << std::endl;
  IntegerVector max_iter(1);
  max_iter[0]  = RcppDeepState_int();
  qs::c_qsave(max_iter,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/lnorm_g_C/inputs/max_iter.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_iter values: "<< max_iter << std::endl;
  NumericVector tol(1);
  tol[0]  = RcppDeepState_double();
  qs::c_qsave(tol,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/lnorm_g_C/inputs/tol.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tol values: "<< tol << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    lnorm_g_C(data,pi,mulog,sdlog,max_iter[0],tol[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
