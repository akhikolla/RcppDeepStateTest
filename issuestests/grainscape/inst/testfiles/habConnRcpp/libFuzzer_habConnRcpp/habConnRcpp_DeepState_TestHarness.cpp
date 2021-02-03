#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List habConnRcpp(NumericVector cost, NumericVector patches, int ncol, int nrow);

TEST(grainscape_deepstate_test,habConnRcpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector cost  = RcppDeepState_NumericVector();
  std::string cost_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/grainscape/inst/testfiles/habConnRcpp/libFuzzer_habConnRcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cost.qs";
  qs::c_qsave(cost,cost_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cost values: "<< cost << std::endl;
  NumericVector patches  = RcppDeepState_NumericVector();
  std::string patches_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/grainscape/inst/testfiles/habConnRcpp/libFuzzer_habConnRcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_patches.qs";
  qs::c_qsave(patches,patches_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "patches values: "<< patches << std::endl;
  IntegerVector ncol(1);
  ncol[0]  = RcppDeepState_int();
  std::string ncol_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/grainscape/inst/testfiles/habConnRcpp/libFuzzer_habConnRcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ncol.qs";
  qs::c_qsave(ncol,ncol_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ncol values: "<< ncol << std::endl;
  IntegerVector nrow(1);
  nrow[0]  = RcppDeepState_int();
  std::string nrow_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/grainscape/inst/testfiles/habConnRcpp/libFuzzer_habConnRcpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nrow.qs";
  qs::c_qsave(nrow,nrow_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nrow values: "<< nrow << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    habConnRcpp(cost,patches,ncol[0],nrow[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
