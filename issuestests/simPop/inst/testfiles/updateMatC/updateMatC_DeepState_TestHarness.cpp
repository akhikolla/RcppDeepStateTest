#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix updateMatC(NumericMatrix M, NumericVector add_row, NumericVector add_col, NumericVector remove_row, NumericVector remove_col, NumericVector hhsize, NumericVector hhid);

TEST(simPop_deepstate_test,updateMatC_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix M  = RcppDeepState_NumericMatrix();
  qs::c_qsave(M,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/inputs/M.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "M values: "<< M << std::endl;
  NumericVector add_row  = RcppDeepState_NumericVector();
  qs::c_qsave(add_row,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/inputs/add_row.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "add_row values: "<< add_row << std::endl;
  NumericVector add_col  = RcppDeepState_NumericVector();
  qs::c_qsave(add_col,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/inputs/add_col.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "add_col values: "<< add_col << std::endl;
  NumericVector remove_row  = RcppDeepState_NumericVector();
  qs::c_qsave(remove_row,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/inputs/remove_row.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "remove_row values: "<< remove_row << std::endl;
  NumericVector remove_col  = RcppDeepState_NumericVector();
  qs::c_qsave(remove_col,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/inputs/remove_col.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "remove_col values: "<< remove_col << std::endl;
  NumericVector hhsize  = RcppDeepState_NumericVector();
  qs::c_qsave(hhsize,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/inputs/hhsize.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "hhsize values: "<< hhsize << std::endl;
  NumericVector hhid  = RcppDeepState_NumericVector();
  qs::c_qsave(hhid,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/updateMatC/inputs/hhid.qs",
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
