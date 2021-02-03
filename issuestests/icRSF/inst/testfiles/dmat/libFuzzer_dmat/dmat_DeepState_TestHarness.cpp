#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix dmat(NumericVector id, NumericVector time, IntegerVector result, double phi1, double phi0, double negpred);

TEST(icRSF_deepstate_test,dmat_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector id  = RcppDeepState_NumericVector();
  std::string id_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/dmat/libFuzzer_dmat/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_id.qs";
  qs::c_qsave(id,id_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "id values: "<< id << std::endl;
  NumericVector time  = RcppDeepState_NumericVector();
  std::string time_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/dmat/libFuzzer_dmat/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_time.qs";
  qs::c_qsave(time,time_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "time values: "<< time << std::endl;
  IntegerVector result  = RcppDeepState_IntegerVector();
  std::string result_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/dmat/libFuzzer_dmat/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_result.qs";
  qs::c_qsave(result,result_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "result values: "<< result << std::endl;
  NumericVector phi1(1);
  phi1[0]  = RcppDeepState_double();
  std::string phi1_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/dmat/libFuzzer_dmat/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_phi1.qs";
  qs::c_qsave(phi1,phi1_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi1 values: "<< phi1 << std::endl;
  NumericVector phi0(1);
  phi0[0]  = RcppDeepState_double();
  std::string phi0_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/dmat/libFuzzer_dmat/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_phi0.qs";
  qs::c_qsave(phi0,phi0_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "phi0 values: "<< phi0 << std::endl;
  NumericVector negpred(1);
  negpred[0]  = RcppDeepState_double();
  std::string negpred_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/icRSF/inst/testfiles/dmat/libFuzzer_dmat/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_negpred.qs";
  qs::c_qsave(negpred,negpred_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "negpred values: "<< negpred << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    dmat(id,time,result,phi1[0],phi0[0],negpred[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
