#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector weib_bisection_C(NumericVector n, NumericVector ex, NumericVector tx, double tol, int max_iter, double xleft, double xright);

TEST(mixR_deepstate_test,weib_bisection_C_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector n  = RcppDeepState_NumericVector();
  std::string n_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/libFuzzer_weib_bisection_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n.qs";
  qs::c_qsave(n,n_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector ex  = RcppDeepState_NumericVector();
  std::string ex_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/libFuzzer_weib_bisection_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ex.qs";
  qs::c_qsave(ex,ex_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ex values: "<< ex << std::endl;
  NumericVector tx  = RcppDeepState_NumericVector();
  std::string tx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/libFuzzer_weib_bisection_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tx.qs";
  qs::c_qsave(tx,tx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tx values: "<< tx << std::endl;
  NumericVector tol(1);
  tol[0]  = RcppDeepState_double();
  std::string tol_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/libFuzzer_weib_bisection_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tol.qs";
  qs::c_qsave(tol,tol_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tol values: "<< tol << std::endl;
  IntegerVector max_iter(1);
  max_iter[0]  = RcppDeepState_int();
  std::string max_iter_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/libFuzzer_weib_bisection_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_max_iter.qs";
  qs::c_qsave(max_iter,max_iter_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_iter values: "<< max_iter << std::endl;
  NumericVector xleft(1);
  xleft[0]  = RcppDeepState_double();
  std::string xleft_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/libFuzzer_weib_bisection_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_xleft.qs";
  qs::c_qsave(xleft,xleft_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xleft values: "<< xleft << std::endl;
  NumericVector xright(1);
  xright[0]  = RcppDeepState_double();
  std::string xright_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mixR/inst/testfiles/weib_bisection_C/libFuzzer_weib_bisection_C/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_xright.qs";
  qs::c_qsave(xright,xright_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xright values: "<< xright << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    weib_bisection_C(n,ex,tx,tol[0],max_iter[0],xleft[0],xright[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
