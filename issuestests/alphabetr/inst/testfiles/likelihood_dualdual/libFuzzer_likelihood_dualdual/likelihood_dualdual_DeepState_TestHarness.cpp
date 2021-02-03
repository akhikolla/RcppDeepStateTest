#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double likelihood_dualdual(double est, double err, NumericVector numb_wells, NumericVector numb_cells, NumericVector numb_sample);

TEST(alphabetr_deepstate_test,likelihood_dualdual_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector est(1);
  est[0]  = RcppDeepState_double();
  std::string est_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/alphabetr/inst/testfiles/likelihood_dualdual/libFuzzer_likelihood_dualdual/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_est.qs";
  qs::c_qsave(est,est_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "est values: "<< est << std::endl;
  NumericVector err(1);
  err[0]  = RcppDeepState_double();
  std::string err_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/alphabetr/inst/testfiles/likelihood_dualdual/libFuzzer_likelihood_dualdual/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_err.qs";
  qs::c_qsave(err,err_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "err values: "<< err << std::endl;
  NumericVector numb_wells  = RcppDeepState_NumericVector();
  std::string numb_wells_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/alphabetr/inst/testfiles/likelihood_dualdual/libFuzzer_likelihood_dualdual/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_numb_wells.qs";
  qs::c_qsave(numb_wells,numb_wells_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "numb_wells values: "<< numb_wells << std::endl;
  NumericVector numb_cells  = RcppDeepState_NumericVector();
  std::string numb_cells_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/alphabetr/inst/testfiles/likelihood_dualdual/libFuzzer_likelihood_dualdual/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_numb_cells.qs";
  qs::c_qsave(numb_cells,numb_cells_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "numb_cells values: "<< numb_cells << std::endl;
  NumericVector numb_sample  = RcppDeepState_NumericVector();
  std::string numb_sample_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/alphabetr/inst/testfiles/likelihood_dualdual/libFuzzer_likelihood_dualdual/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_numb_sample.qs";
  qs::c_qsave(numb_sample,numb_sample_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "numb_sample values: "<< numb_sample << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    likelihood_dualdual(est[0],err[0],numb_wells,numb_cells,numb_sample);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
