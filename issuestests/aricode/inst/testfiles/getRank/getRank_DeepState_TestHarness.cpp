#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List getRank(IntegerVector classi);

TEST(aricode_deepstate_test,getRank_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector classi  = RcppDeepState_IntegerVector();
  qs::c_qsave(classi,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aricode/inst/testfiles/getRank/inputs/classi.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "classi values: "<< classi << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    getRank(classi);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
