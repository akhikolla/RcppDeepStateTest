#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List bsplitC(NumericMatrix Dmat, NumericMatrix Xmat, NumericVector parm);

TEST(icRSF_deepstate_test,bsplitC_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Dmat  = RcppDeepState_NumericMatrix();
  std::string Dmat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/bsplitC/AFL_bsplitC/afl_inputs/" + std::to_string(t) + "_Dmat.qs";
  qs::c_qsave(Dmat,Dmat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Dmat values: "<< Dmat << std::endl;
  NumericMatrix Xmat  = RcppDeepState_NumericMatrix();
  std::string Xmat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/bsplitC/AFL_bsplitC/afl_inputs/" + std::to_string(t) + "_Xmat.qs";
  qs::c_qsave(Xmat,Xmat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Xmat values: "<< Xmat << std::endl;
  NumericVector parm  = RcppDeepState_NumericVector();
  std::string parm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/bsplitC/AFL_bsplitC/afl_inputs/" + std::to_string(t) + "_parm.qs";
  qs::c_qsave(parm,parm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "parm values: "<< parm << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    bsplitC(Dmat,Xmat,parm);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
