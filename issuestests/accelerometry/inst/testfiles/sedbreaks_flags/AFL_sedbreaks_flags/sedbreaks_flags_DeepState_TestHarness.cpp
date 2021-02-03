#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector sedbreaks_flags(IntegerVector counts, IntegerVector weartime, int thresh);

TEST(accelerometry_deepstate_test,sedbreaks_flags_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector counts  = RcppDeepState_IntegerVector();
  std::string counts_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/sedbreaks_flags/AFL_sedbreaks_flags/afl_inputs/" + std::to_string(t) + "_counts.qs";
  qs::c_qsave(counts,counts_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "counts values: "<< counts << std::endl;
  IntegerVector weartime  = RcppDeepState_IntegerVector();
  std::string weartime_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/sedbreaks_flags/AFL_sedbreaks_flags/afl_inputs/" + std::to_string(t) + "_weartime.qs";
  qs::c_qsave(weartime,weartime_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weartime values: "<< weartime << std::endl;
  IntegerVector thresh(1);
  thresh[0]  = RcppDeepState_int();
  std::string thresh_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/sedbreaks_flags/AFL_sedbreaks_flags/afl_inputs/" + std::to_string(t) + "_thresh.qs";
  qs::c_qsave(thresh,thresh_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "thresh values: "<< thresh << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sedbreaks_flags(counts,weartime,thresh[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
