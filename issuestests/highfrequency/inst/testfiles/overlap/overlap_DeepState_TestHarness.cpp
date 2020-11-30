#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

bool overlap(double min1, double max1, double min2, double max2);

TEST(highfrequency_deepstate_test,overlap_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector min1(1);
  min1[0]  = RcppDeepState_double();
  qs::c_qsave(min1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/overlap/inputs/min1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "min1 values: "<< min1 << std::endl;
  NumericVector max1(1);
  max1[0]  = RcppDeepState_double();
  qs::c_qsave(max1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/overlap/inputs/max1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max1 values: "<< max1 << std::endl;
  NumericVector min2(1);
  min2[0]  = RcppDeepState_double();
  qs::c_qsave(min2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/overlap/inputs/min2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "min2 values: "<< min2 << std::endl;
  NumericVector max2(1);
  max2[0]  = RcppDeepState_double();
  qs::c_qsave(max2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/overlap/inputs/max2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max2 values: "<< max2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    overlap(min1[0],max1[0],min2[0],max2[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
