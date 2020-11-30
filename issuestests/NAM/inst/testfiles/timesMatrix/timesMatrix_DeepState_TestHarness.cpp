#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix timesMatrix(NumericMatrix ma1, NumericVector h, NumericMatrix ma2, int rows, int cols);

TEST(NAM_deepstate_test,timesMatrix_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix ma1  = RcppDeepState_NumericMatrix();
  qs::c_qsave(ma1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesMatrix/inputs/ma1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ma1 values: "<< ma1 << std::endl;
  NumericVector h  = RcppDeepState_NumericVector();
  qs::c_qsave(h,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesMatrix/inputs/h.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  NumericMatrix ma2  = RcppDeepState_NumericMatrix();
  qs::c_qsave(ma2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesMatrix/inputs/ma2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ma2 values: "<< ma2 << std::endl;
  IntegerVector rows(1);
  rows[0]  = RcppDeepState_int();
  qs::c_qsave(rows,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesMatrix/inputs/rows.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rows values: "<< rows << std::endl;
  IntegerVector cols(1);
  cols[0]  = RcppDeepState_int();
  qs::c_qsave(cols,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesMatrix/inputs/cols.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cols values: "<< cols << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    timesMatrix(ma1,h,ma2,rows[0],cols[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
