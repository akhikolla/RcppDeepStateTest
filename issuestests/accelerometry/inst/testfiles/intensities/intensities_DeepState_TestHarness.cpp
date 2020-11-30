#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector intensities(IntegerVector counts, IntegerVector int_cuts);

TEST(accelerometry_deepstate_test,intensities_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector counts  = RcppDeepState_IntegerVector();
  qs::c_qsave(counts,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/intensities/inputs/counts.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "counts values: "<< counts << std::endl;
  IntegerVector int_cuts  = RcppDeepState_IntegerVector();
  qs::c_qsave(int_cuts,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/accelerometry/inst/testfiles/intensities/inputs/int_cuts.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "int_cuts values: "<< int_cuts << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    intensities(counts,int_cuts);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
