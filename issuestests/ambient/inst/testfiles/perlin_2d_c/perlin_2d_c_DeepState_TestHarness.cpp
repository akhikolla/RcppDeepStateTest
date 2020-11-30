#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix perlin_2d_c(int height, int width, int seed, double freq, int interp, int fractal, int octaves, double lacunarity, double gain, int pertube, double pertube_amp);

TEST(ambient_deepstate_test,perlin_2d_c_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector height(1);
  height[0]  = RcppDeepState_int();
  qs::c_qsave(height,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/perlin_2d_c/inputs/height.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "height values: "<< height << std::endl;
  IntegerVector width(1);
  width[0]  = RcppDeepState_int();
  qs::c_qsave(width,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/perlin_2d_c/inputs/width.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "width values: "<< width << std::endl;
  IntegerVector seed(1);
  seed[0]  = RcppDeepState_int();
  qs::c_qsave(seed,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/perlin_2d_c/inputs/seed.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seed values: "<< seed << std::endl;
  NumericVector freq(1);
  freq[0]  = RcppDeepState_double();
  qs::c_qsave(freq,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/perlin_2d_c/inputs/freq.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "freq values: "<< freq << std::endl;
  IntegerVector interp(1);
  interp[0]  = RcppDeepState_int();
  qs::c_qsave(interp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/perlin_2d_c/inputs/interp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "interp values: "<< interp << std::endl;
  IntegerVector fractal(1);
  fractal[0]  = RcppDeepState_int();
  qs::c_qsave(fractal,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/perlin_2d_c/inputs/fractal.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "fractal values: "<< fractal << std::endl;
  IntegerVector octaves(1);
  octaves[0]  = RcppDeepState_int();
  qs::c_qsave(octaves,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/perlin_2d_c/inputs/octaves.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "octaves values: "<< octaves << std::endl;
  NumericVector lacunarity(1);
  lacunarity[0]  = RcppDeepState_double();
  qs::c_qsave(lacunarity,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/perlin_2d_c/inputs/lacunarity.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lacunarity values: "<< lacunarity << std::endl;
  NumericVector gain(1);
  gain[0]  = RcppDeepState_double();
  qs::c_qsave(gain,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/perlin_2d_c/inputs/gain.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "gain values: "<< gain << std::endl;
  IntegerVector pertube(1);
  pertube[0]  = RcppDeepState_int();
  qs::c_qsave(pertube,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/perlin_2d_c/inputs/pertube.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pertube values: "<< pertube << std::endl;
  NumericVector pertube_amp(1);
  pertube_amp[0]  = RcppDeepState_double();
  qs::c_qsave(pertube_amp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/perlin_2d_c/inputs/pertube_amp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pertube_amp values: "<< pertube_amp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    perlin_2d_c(height[0],width[0],seed[0],freq[0],interp[0],fractal[0],octaves[0],lacunarity[0],gain[0],pertube[0],pertube_amp[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
