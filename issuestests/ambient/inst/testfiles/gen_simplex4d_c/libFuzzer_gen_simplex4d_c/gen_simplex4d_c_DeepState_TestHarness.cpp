#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector gen_simplex4d_c(NumericVector x, NumericVector y, NumericVector z, NumericVector t, double freq, int seed);

TEST(ambient_deepstate_test,gen_simplex4d_c_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_simplex4d_c/libFuzzer_gen_simplex4d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_simplex4d_c/libFuzzer_gen_simplex4d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_simplex4d_c/libFuzzer_gen_simplex4d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector t  = RcppDeepState_NumericVector();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_simplex4d_c/libFuzzer_gen_simplex4d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_t.qs";
  qs::c_qsave(t,t_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  NumericVector freq(1);
  freq[0]  = RcppDeepState_double();
  std::string freq_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_simplex4d_c/libFuzzer_gen_simplex4d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_freq.qs";
  qs::c_qsave(freq,freq_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "freq values: "<< freq << std::endl;
  IntegerVector seed(1);
  seed[0]  = RcppDeepState_int();
  std::string seed_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_simplex4d_c/libFuzzer_gen_simplex4d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_seed.qs";
  qs::c_qsave(seed,seed_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seed values: "<< seed << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gen_simplex4d_c(x,y,z,t,freq[0],seed[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
