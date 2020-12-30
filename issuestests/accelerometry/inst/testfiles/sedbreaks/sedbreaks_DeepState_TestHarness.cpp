#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int sedbreaks(IntegerVector counts, IntegerVector weartime, int thresh);

TEST(accelerometry_deepstate_test,sedbreaks_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector counts  = RcppDeepState_IntegerVector();
  qs::c_qsave(counts,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/sedbreaks/inputs/counts.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "counts values: "<< counts << std::endl;
  IntegerVector weartime  = RcppDeepState_IntegerVector();
  qs::c_qsave(weartime,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/sedbreaks/inputs/weartime.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weartime values: "<< weartime << std::endl;
  IntegerVector thresh(1);
  thresh[0]  = RcppDeepState_int();
  qs::c_qsave(thresh,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/sedbreaks/inputs/thresh.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "thresh values: "<< thresh << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    sedbreaks(counts,weartime,thresh[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
