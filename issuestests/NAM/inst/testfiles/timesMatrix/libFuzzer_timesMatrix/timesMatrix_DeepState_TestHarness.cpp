#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix timesMatrix(NumericMatrix ma1, NumericVector h, NumericMatrix ma2, int rows, int cols);

TEST(NAM_deepstate_test,timesMatrix_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix ma1  = RcppDeepState_NumericMatrix();
  std::string ma1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesMatrix/libFuzzer_timesMatrix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ma1.qs";
  qs::c_qsave(ma1,ma1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ma1 values: "<< ma1 << std::endl;
  NumericVector h  = RcppDeepState_NumericVector();
  std::string h_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesMatrix/libFuzzer_timesMatrix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_h.qs";
  qs::c_qsave(h,h_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "h values: "<< h << std::endl;
  NumericMatrix ma2  = RcppDeepState_NumericMatrix();
  std::string ma2_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesMatrix/libFuzzer_timesMatrix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ma2.qs";
  qs::c_qsave(ma2,ma2_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ma2 values: "<< ma2 << std::endl;
  IntegerVector rows(1);
  rows[0]  = RcppDeepState_int();
  std::string rows_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesMatrix/libFuzzer_timesMatrix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_rows.qs";
  qs::c_qsave(rows,rows_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rows values: "<< rows << std::endl;
  IntegerVector cols(1);
  cols[0]  = RcppDeepState_int();
  std::string cols_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/NAM/inst/testfiles/timesMatrix/libFuzzer_timesMatrix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cols.qs";
  qs::c_qsave(cols,cols_t,
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
