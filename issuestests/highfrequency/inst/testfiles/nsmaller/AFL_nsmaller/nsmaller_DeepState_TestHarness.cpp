#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

int nsmaller(IntegerVector times, IntegerVector lengths, int start, int end, int max);

TEST(highfrequency_deepstate_test,nsmaller_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector times  = RcppDeepState_IntegerVector();
  std::string times_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/nsmaller/AFL_nsmaller/afl_inputs/" + std::to_string(t) + "_times.qs";
  qs::c_qsave(times,times_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "times values: "<< times << std::endl;
  IntegerVector lengths  = RcppDeepState_IntegerVector();
  std::string lengths_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/nsmaller/AFL_nsmaller/afl_inputs/" + std::to_string(t) + "_lengths.qs";
  qs::c_qsave(lengths,lengths_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lengths values: "<< lengths << std::endl;
  IntegerVector start(1);
  start[0]  = RcppDeepState_int();
  std::string start_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/nsmaller/AFL_nsmaller/afl_inputs/" + std::to_string(t) + "_start.qs";
  qs::c_qsave(start,start_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  IntegerVector end(1);
  end[0]  = RcppDeepState_int();
  std::string end_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/nsmaller/AFL_nsmaller/afl_inputs/" + std::to_string(t) + "_end.qs";
  qs::c_qsave(end,end_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "end values: "<< end << std::endl;
  IntegerVector max(1);
  max[0]  = RcppDeepState_int();
  std::string max_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/nsmaller/AFL_nsmaller/afl_inputs/" + std::to_string(t) + "_max.qs";
  qs::c_qsave(max,max_t,
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
