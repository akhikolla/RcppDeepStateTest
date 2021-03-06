#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector gen_worley3d_c(NumericVector x, NumericVector y, NumericVector z, double freq, int seed, int dist, int value, IntegerVector dist2ind, double jitter);

TEST(ambient_deepstate_test,gen_worley3d_c_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley3d_c/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley3d_c/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector z  = RcppDeepState_NumericVector();
  qs::c_qsave(z,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley3d_c/inputs/z.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector freq(1);
  freq[0]  = RcppDeepState_double();
  qs::c_qsave(freq,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley3d_c/inputs/freq.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "freq values: "<< freq << std::endl;
  IntegerVector seed(1);
  seed[0]  = RcppDeepState_int();
  qs::c_qsave(seed,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley3d_c/inputs/seed.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seed values: "<< seed << std::endl;
  IntegerVector dist(1);
  dist[0]  = RcppDeepState_int();
  qs::c_qsave(dist,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley3d_c/inputs/dist.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dist values: "<< dist << std::endl;
  IntegerVector value(1);
  value[0]  = RcppDeepState_int();
  qs::c_qsave(value,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley3d_c/inputs/value.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "value values: "<< value << std::endl;
  IntegerVector dist2ind  = RcppDeepState_IntegerVector();
  qs::c_qsave(dist2ind,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley3d_c/inputs/dist2ind.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dist2ind values: "<< dist2ind << std::endl;
  NumericVector jitter(1);
  jitter[0]  = RcppDeepState_double();
  qs::c_qsave(jitter,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/ambient/inst/testfiles/gen_worley3d_c/inputs/jitter.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "jitter values: "<< jitter << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    gen_worley3d_c(x,y,z,freq[0],seed[0],dist[0],value[0],dist2ind,jitter[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
