#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector SPC(NumericVector y, NumericVector blk, NumericVector row, NumericVector col, double rN, double cN);

TEST(NAM_deepstate_test,SPC_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SPC/AFL_SPC/afl_inputs/" + std::to_string(t) + "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector blk  = RcppDeepState_NumericVector();
  std::string blk_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SPC/AFL_SPC/afl_inputs/" + std::to_string(t) + "_blk.qs";
  qs::c_qsave(blk,blk_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "blk values: "<< blk << std::endl;
  NumericVector row  = RcppDeepState_NumericVector();
  std::string row_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SPC/AFL_SPC/afl_inputs/" + std::to_string(t) + "_row.qs";
  qs::c_qsave(row,row_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "row values: "<< row << std::endl;
  NumericVector col  = RcppDeepState_NumericVector();
  std::string col_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SPC/AFL_SPC/afl_inputs/" + std::to_string(t) + "_col.qs";
  qs::c_qsave(col,col_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "col values: "<< col << std::endl;
  NumericVector rN(1);
  rN[0]  = RcppDeepState_double();
  std::string rN_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SPC/AFL_SPC/afl_inputs/" + std::to_string(t) + "_rN.qs";
  qs::c_qsave(rN,rN_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rN values: "<< rN << std::endl;
  NumericVector cN(1);
  cN[0]  = RcppDeepState_double();
  std::string cN_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/SPC/AFL_SPC/afl_inputs/" + std::to_string(t) + "_cN.qs";
  qs::c_qsave(cN,cN_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cN values: "<< cN << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    SPC(y,blk,row,col,rN[0],cN[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
