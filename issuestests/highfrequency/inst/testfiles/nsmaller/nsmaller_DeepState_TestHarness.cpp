#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int nsmaller(IntegerVector times, IntegerVector lengths, int start, int end, int max);

TEST(highfrequency_deepstate_test,nsmaller_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector times  = RcppDeepState_IntegerVector();
  qs::c_qsave(times,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/nsmaller/inputs/times.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "times values: "<< times << std::endl;
  IntegerVector lengths  = RcppDeepState_IntegerVector();
  qs::c_qsave(lengths,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/nsmaller/inputs/lengths.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lengths values: "<< lengths << std::endl;
  IntegerVector start(1);
  start[0]  = RcppDeepState_int();
  qs::c_qsave(start,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/nsmaller/inputs/start.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  IntegerVector end(1);
  end[0]  = RcppDeepState_int();
  qs::c_qsave(end,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/nsmaller/inputs/end.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "end values: "<< end << std::endl;
  IntegerVector max(1);
  max[0]  = RcppDeepState_int();
  qs::c_qsave(max,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/nsmaller/inputs/max.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max values: "<< max << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    nsmaller(times,lengths,start[0],end[0],max[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
