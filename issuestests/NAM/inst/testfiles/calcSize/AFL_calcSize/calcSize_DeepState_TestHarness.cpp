#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int calcSize(NumericVector col, NumericVector fam);

TEST(NAM_deepstate_test,calcSize_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector col  = RcppDeepState_NumericVector();
  std::string col_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/calcSize/AFL_calcSize/afl_inputs/" + std::to_string(t) + "_col.qs";
  qs::c_qsave(col,col_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "col values: "<< col << std::endl;
  NumericVector fam  = RcppDeepState_NumericVector();
  std::string fam_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/calcSize/AFL_calcSize/afl_inputs/" + std::to_string(t) + "_fam.qs";
  qs::c_qsave(fam,fam_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fam values: "<< fam << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    calcSize(col,fam);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
