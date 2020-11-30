#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector ipu_work(NumericMatrix inp, NumericVector con, NumericVector w, double eps, IntegerVector verbose);

TEST(simPop_deepstate_test,ipu_work_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix inp  = RcppDeepState_NumericMatrix();
  std::string inp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/ipu_work/AFL_ipu_work/afl_inputs/" + std::to_string(t) + "_inp.qs";
  qs::c_qsave(inp,inp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "inp values: "<< inp << std::endl;
  NumericVector con  = RcppDeepState_NumericVector();
  std::string con_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/ipu_work/AFL_ipu_work/afl_inputs/" + std::to_string(t) + "_con.qs";
  qs::c_qsave(con,con_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "con values: "<< con << std::endl;
  NumericVector w  = RcppDeepState_NumericVector();
  std::string w_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/ipu_work/AFL_ipu_work/afl_inputs/" + std::to_string(t) + "_w.qs";
  qs::c_qsave(w,w_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  NumericVector eps(1);
  eps[0]  = RcppDeepState_double();
  std::string eps_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/ipu_work/AFL_ipu_work/afl_inputs/" + std::to_string(t) + "_eps.qs";
  qs::c_qsave(eps,eps_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps values: "<< eps << std::endl;
  IntegerVector verbose  = RcppDeepState_IntegerVector();
  std::string verbose_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/ipu_work/AFL_ipu_work/afl_inputs/" + std::to_string(t) + "_verbose.qs";
  qs::c_qsave(verbose,verbose_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "verbose values: "<< verbose << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ipu_work(inp,con,w,eps[0],verbose);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
