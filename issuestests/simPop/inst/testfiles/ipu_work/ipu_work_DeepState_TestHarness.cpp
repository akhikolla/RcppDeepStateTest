#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector ipu_work(NumericMatrix inp, NumericVector con, NumericVector w, double eps, IntegerVector verbose);

TEST(simPop_deepstate_test,ipu_work_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix inp  = RcppDeepState_NumericMatrix();
  qs::c_qsave(inp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/ipu_work/inputs/inp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "inp values: "<< inp << std::endl;
  NumericVector con  = RcppDeepState_NumericVector();
  qs::c_qsave(con,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/ipu_work/inputs/con.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "con values: "<< con << std::endl;
  NumericVector w  = RcppDeepState_NumericVector();
  qs::c_qsave(w,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/ipu_work/inputs/w.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "w values: "<< w << std::endl;
  NumericVector eps(1);
  eps[0]  = RcppDeepState_double();
  qs::c_qsave(eps,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/ipu_work/inputs/eps.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps values: "<< eps << std::endl;
  IntegerVector verbose  = RcppDeepState_IntegerVector();
  qs::c_qsave(verbose,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/ipu_work/inputs/verbose.qs",
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
