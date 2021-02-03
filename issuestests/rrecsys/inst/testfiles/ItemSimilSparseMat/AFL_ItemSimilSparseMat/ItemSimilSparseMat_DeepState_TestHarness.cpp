#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix ItemSimilSparseMat(NumericMatrix x, int dim, int DAMP);

TEST(rrecsys_deepstate_test,ItemSimilSparseMat_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/ItemSimilSparseMat/AFL_ItemSimilSparseMat/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector dim(1);
  dim[0]  = RcppDeepState_int();
  std::string dim_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/ItemSimilSparseMat/AFL_ItemSimilSparseMat/afl_inputs/" + std::to_string(t) + "_dim.qs";
  qs::c_qsave(dim,dim_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dim values: "<< dim << std::endl;
  IntegerVector DAMP(1);
  DAMP[0]  = RcppDeepState_int();
  std::string DAMP_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/ItemSimilSparseMat/AFL_ItemSimilSparseMat/afl_inputs/" + std::to_string(t) + "_DAMP.qs";
  qs::c_qsave(DAMP,DAMP_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "DAMP values: "<< DAMP << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ItemSimilSparseMat(x,dim[0],DAMP[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
