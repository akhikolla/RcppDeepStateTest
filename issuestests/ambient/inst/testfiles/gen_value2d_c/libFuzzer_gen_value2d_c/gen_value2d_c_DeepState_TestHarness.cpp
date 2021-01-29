#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector gen_value2d_c(NumericVector x, NumericVector y, double freq, int seed, int interp);

TEST(ambient_deepstate_test,gen_value2d_c_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_value2d_c/libFuzzer_gen_value2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_value2d_c/libFuzzer_gen_value2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector freq(1);
  freq[0]  = RcppDeepState_double();
  std::string freq_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_value2d_c/libFuzzer_gen_value2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_freq.qs";
  qs::c_qsave(freq,freq_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "freq values: "<< freq << std::endl;
  IntegerVector seed(1);
  seed[0]  = RcppDeepState_int();
  std::string seed_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_value2d_c/libFuzzer_gen_value2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_seed.qs";
  qs::c_qsave(seed,seed_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seed values: "<< seed << std::endl;
  IntegerVector interp(1);
  interp[0]  = RcppDeepState_int();
  std::string interp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_value2d_c/libFuzzer_gen_value2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_interp.qs";
  qs::c_qsave(interp,interp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "interp values: "<< interp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gen_value2d_c(x,y,freq[0],seed[0],interp[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
