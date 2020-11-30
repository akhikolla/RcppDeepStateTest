#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix updateMatC(NumericMatrix M, NumericVector add_row, NumericVector add_col, NumericVector remove_row, NumericVector remove_col, NumericVector hhsize, NumericVector hhid);

TEST(simPop_deepstate_test,updateMatC_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix M  = RcppDeepState_NumericMatrix();
  std::string M_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/AFL_updateMatC/afl_inputs/" + std::to_string(t) + "_M.qs";
  qs::c_qsave(M,M_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "M values: "<< M << std::endl;
  NumericVector add_row  = RcppDeepState_NumericVector();
  std::string add_row_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/AFL_updateMatC/afl_inputs/" + std::to_string(t) + "_add_row.qs";
  qs::c_qsave(add_row,add_row_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "add_row values: "<< add_row << std::endl;
  NumericVector add_col  = RcppDeepState_NumericVector();
  std::string add_col_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/AFL_updateMatC/afl_inputs/" + std::to_string(t) + "_add_col.qs";
  qs::c_qsave(add_col,add_col_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "add_col values: "<< add_col << std::endl;
  NumericVector remove_row  = RcppDeepState_NumericVector();
  std::string remove_row_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/AFL_updateMatC/afl_inputs/" + std::to_string(t) + "_remove_row.qs";
  qs::c_qsave(remove_row,remove_row_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "remove_row values: "<< remove_row << std::endl;
  NumericVector remove_col  = RcppDeepState_NumericVector();
  std::string remove_col_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/AFL_updateMatC/afl_inputs/" + std::to_string(t) + "_remove_col.qs";
  qs::c_qsave(remove_col,remove_col_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "remove_col values: "<< remove_col << std::endl;
  NumericVector hhsize  = RcppDeepState_NumericVector();
  std::string hhsize_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/AFL_updateMatC/afl_inputs/" + std::to_string(t) + "_hhsize.qs";
  qs::c_qsave(hhsize,hhsize_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "hhsize values: "<< hhsize << std::endl;
  NumericVector hhid  = RcppDeepState_NumericVector();
  std::string hhid_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/AFL_updateMatC/afl_inputs/" + std::to_string(t) + "_hhid.qs";
  qs::c_qsave(hhid,hhid_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "hhid values: "<< hhid << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    updateMatC(M,add_row,add_col,remove_row,remove_col,hhsize,hhid);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
