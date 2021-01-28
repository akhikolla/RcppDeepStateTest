#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::imat contingency_table(double precision, double rec, int length, double baserate);

TEST(rhoR_deepstate_test,contingency_table_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector precision(1);
  precision[0]  = RcppDeepState_double();
  std::string precision_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/contingency_table/libFuzzer_contingency_table/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_precision.qs";
  qs::c_qsave(precision,precision_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "precision values: "<< precision << std::endl;
  NumericVector rec(1);
  rec[0]  = RcppDeepState_double();
  std::string rec_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/contingency_table/libFuzzer_contingency_table/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_rec.qs";
  qs::c_qsave(rec,rec_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "rec values: "<< rec << std::endl;
  IntegerVector length(1);
  length[0]  = RcppDeepState_int();
  std::string length_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/contingency_table/libFuzzer_contingency_table/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_length.qs";
  qs::c_qsave(length,length_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "length values: "<< length << std::endl;
  NumericVector baserate(1);
  baserate[0]  = RcppDeepState_double();
  std::string baserate_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rhoR/inst/testfiles/contingency_table/libFuzzer_contingency_table/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_baserate.qs";
  qs::c_qsave(baserate,baserate_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "baserate values: "<< baserate << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    contingency_table(precision[0],rec[0],length[0],baserate[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
