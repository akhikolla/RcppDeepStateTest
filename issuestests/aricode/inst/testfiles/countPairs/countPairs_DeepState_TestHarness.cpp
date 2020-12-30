#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List countPairs(IntegerVector classi1, IntegerVector classi2, IntegerVector order);

TEST(aricode_deepstate_test,countPairs_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector classi1  = RcppDeepState_IntegerVector();
  qs::c_qsave(classi1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aricode/inst/testfiles/countPairs/inputs/classi1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "classi1 values: "<< classi1 << std::endl;
  IntegerVector classi2  = RcppDeepState_IntegerVector();
  qs::c_qsave(classi2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aricode/inst/testfiles/countPairs/inputs/classi2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "classi2 values: "<< classi2 << std::endl;
  IntegerVector order  = RcppDeepState_IntegerVector();
  qs::c_qsave(order,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aricode/inst/testfiles/countPairs/inputs/order.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "order values: "<< order << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    countPairs(classi1,classi2,order);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
