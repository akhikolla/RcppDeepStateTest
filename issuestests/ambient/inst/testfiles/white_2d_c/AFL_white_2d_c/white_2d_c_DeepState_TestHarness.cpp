#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix white_2d_c(int height, int width, int seed, double freq, int pertube, double pertube_amp);

TEST(ambient_deepstate_test,white_2d_c_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector height(1);
  height[0]  = RcppDeepState_int();
  std::string height_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/white_2d_c/AFL_white_2d_c/afl_inputs/" + std::to_string(t) + "_height.qs";
  qs::c_qsave(height,height_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "height values: "<< height << std::endl;
  IntegerVector width(1);
  width[0]  = RcppDeepState_int();
  std::string width_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/white_2d_c/AFL_white_2d_c/afl_inputs/" + std::to_string(t) + "_width.qs";
  qs::c_qsave(width,width_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "width values: "<< width << std::endl;
  IntegerVector seed(1);
  seed[0]  = RcppDeepState_int();
  std::string seed_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/white_2d_c/AFL_white_2d_c/afl_inputs/" + std::to_string(t) + "_seed.qs";
  qs::c_qsave(seed,seed_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seed values: "<< seed << std::endl;
  NumericVector freq(1);
  freq[0]  = RcppDeepState_double();
  std::string freq_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/white_2d_c/AFL_white_2d_c/afl_inputs/" + std::to_string(t) + "_freq.qs";
  qs::c_qsave(freq,freq_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "freq values: "<< freq << std::endl;
  IntegerVector pertube(1);
  pertube[0]  = RcppDeepState_int();
  std::string pertube_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/white_2d_c/AFL_white_2d_c/afl_inputs/" + std::to_string(t) + "_pertube.qs";
  qs::c_qsave(pertube,pertube_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pertube values: "<< pertube << std::endl;
  NumericVector pertube_amp(1);
  pertube_amp[0]  = RcppDeepState_double();
  std::string pertube_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/white_2d_c/AFL_white_2d_c/afl_inputs/" + std::to_string(t) + "_pertube.qs";
  std::string pertube_amp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/white_2d_c/AFL_white_2d_c/afl_inputs/" + std::to_string(t) + "_pertube_amp.qs";
  qs::c_qsave(pertube_amp,pertube_amp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pertube_amp values: "<< pertube_amp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    white_2d_c(height[0],width[0],seed[0],freq[0],pertube[0],pertube_amp[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
