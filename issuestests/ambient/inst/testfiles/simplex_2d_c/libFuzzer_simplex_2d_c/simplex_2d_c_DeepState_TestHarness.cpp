#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix simplex_2d_c(int height, int width, int seed, double freq, int fractal, int octaves, double lacunarity, double gain, int pertube, double pertube_amp);

TEST(ambient_deepstate_test,simplex_2d_c_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector height(1);
  height[0]  = RcppDeepState_int();
  std::string height_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/simplex_2d_c/libFuzzer_simplex_2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_height.qs";
  qs::c_qsave(height,height_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "height values: "<< height << std::endl;
  IntegerVector width(1);
  width[0]  = RcppDeepState_int();
  std::string width_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/simplex_2d_c/libFuzzer_simplex_2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_width.qs";
  qs::c_qsave(width,width_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "width values: "<< width << std::endl;
  IntegerVector seed(1);
  seed[0]  = RcppDeepState_int();
  std::string seed_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/simplex_2d_c/libFuzzer_simplex_2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_seed.qs";
  qs::c_qsave(seed,seed_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seed values: "<< seed << std::endl;
  NumericVector freq(1);
  freq[0]  = RcppDeepState_double();
  std::string freq_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/simplex_2d_c/libFuzzer_simplex_2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_freq.qs";
  qs::c_qsave(freq,freq_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "freq values: "<< freq << std::endl;
  IntegerVector fractal(1);
  fractal[0]  = RcppDeepState_int();
  std::string fractal_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/simplex_2d_c/libFuzzer_simplex_2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_fractal.qs";
  qs::c_qsave(fractal,fractal_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fractal values: "<< fractal << std::endl;
  IntegerVector octaves(1);
  octaves[0]  = RcppDeepState_int();
  std::string octaves_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/simplex_2d_c/libFuzzer_simplex_2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_octaves.qs";
  qs::c_qsave(octaves,octaves_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "octaves values: "<< octaves << std::endl;
  NumericVector lacunarity(1);
  lacunarity[0]  = RcppDeepState_double();
  std::string lacunarity_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/simplex_2d_c/libFuzzer_simplex_2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_lacunarity.qs";
  qs::c_qsave(lacunarity,lacunarity_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lacunarity values: "<< lacunarity << std::endl;
  NumericVector gain(1);
  gain[0]  = RcppDeepState_double();
  std::string gain_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/simplex_2d_c/libFuzzer_simplex_2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_gain.qs";
  qs::c_qsave(gain,gain_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gain values: "<< gain << std::endl;
  IntegerVector pertube(1);
  pertube[0]  = RcppDeepState_int();
  std::string pertube_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/simplex_2d_c/libFuzzer_simplex_2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pertube.qs";
  qs::c_qsave(pertube,pertube_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pertube values: "<< pertube << std::endl;
  NumericVector pertube_amp(1);
  pertube_amp[0]  = RcppDeepState_double();
  std::string pertube_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/simplex_2d_c/libFuzzer_simplex_2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pertube.qs";
  std::string pertube_amp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/simplex_2d_c/libFuzzer_simplex_2d_c/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pertube_amp.qs";
  qs::c_qsave(pertube_amp,pertube_amp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pertube_amp values: "<< pertube_amp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    simplex_2d_c(height[0],width[0],seed[0],freq[0],fractal[0],octaves[0],lacunarity[0],gain[0],pertube[0],pertube_amp[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
