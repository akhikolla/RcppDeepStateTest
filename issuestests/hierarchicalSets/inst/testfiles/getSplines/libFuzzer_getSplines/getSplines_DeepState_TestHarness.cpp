#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List getSplines(NumericVector x, NumericVector y, IntegerVector id, int detail);

TEST(hierarchicalSets_deepstate_test,getSplines_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/getSplines/libFuzzer_getSplines/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/getSplines/libFuzzer_getSplines/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  IntegerVector id  = RcppDeepState_IntegerVector();
  std::string id_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/getSplines/libFuzzer_getSplines/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_id.qs";
  qs::c_qsave(id,id_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "id values: "<< id << std::endl;
  IntegerVector detail(1);
  detail[0]  = RcppDeepState_int();
  std::string detail_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/hierarchicalSets/inst/testfiles/getSplines/libFuzzer_getSplines/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_detail.qs";
  qs::c_qsave(detail,detail_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "detail values: "<< detail << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    getSplines(x,y,id,detail[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
