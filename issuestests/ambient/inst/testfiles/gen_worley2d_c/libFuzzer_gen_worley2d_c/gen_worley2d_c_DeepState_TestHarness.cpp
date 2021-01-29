#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector gen_worley2d_c(NumericVector x, NumericVector y, double freq, int seed, int dist, int value, IntegerVector dist2ind, double jitter);

TEST(ambient_deepstate_test,gen_worley2d_c_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley2d_c/libFuzzer_gen_worley2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley2d_c/libFuzzer_gen_worley2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector freq(1);
  freq[0]  = RcppDeepState_double();
  std::string freq_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley2d_c/libFuzzer_gen_worley2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_freq.qs";
  qs::c_qsave(freq,freq_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "freq values: "<< freq << std::endl;
  IntegerVector seed(1);
  seed[0]  = RcppDeepState_int();
  std::string seed_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley2d_c/libFuzzer_gen_worley2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_seed.qs";
  qs::c_qsave(seed,seed_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seed values: "<< seed << std::endl;
  IntegerVector dist(1);
  dist[0]  = RcppDeepState_int();
  std::string dist_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley2d_c/libFuzzer_gen_worley2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_dist.qs";
  qs::c_qsave(dist,dist_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dist values: "<< dist << std::endl;
  IntegerVector value(1);
  value[0]  = RcppDeepState_int();
  std::string value_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley2d_c/libFuzzer_gen_worley2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_value.qs";
  qs::c_qsave(value,value_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "value values: "<< value << std::endl;
  IntegerVector dist2ind  = RcppDeepState_IntegerVector();
  std::string dist_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley2d_c/libFuzzer_gen_worley2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_dist.qs";
  std::string dist2ind_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley2d_c/libFuzzer_gen_worley2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_dist2ind.qs";
  qs::c_qsave(dist2ind,dist2ind_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dist2ind values: "<< dist2ind << std::endl;
  NumericVector jitter(1);
  jitter[0]  = RcppDeepState_double();
  std::string jitter_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley2d_c/libFuzzer_gen_worley2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_jitter.qs";
  qs::c_qsave(jitter,jitter_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "jitter values: "<< jitter << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gen_worley2d_c(x,y,freq[0],seed[0],dist[0],value[0],dist2ind,jitter[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
