#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List do_landsat_numeric_to_bytes(NumericMatrix m, IntegerVector bits);

TEST(oce_deepstate_test,do_landsat_numeric_to_bytes_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix m  = RcppDeepState_NumericMatrix();
  qs::c_qsave(m,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_landsat_numeric_to_bytes/inputs/m.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "m values: "<< m << std::endl;
  IntegerVector bits  = RcppDeepState_IntegerVector();
  qs::c_qsave(bits,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_landsat_numeric_to_bytes/inputs/bits.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bits values: "<< bits << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_landsat_numeric_to_bytes(m,bits);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
