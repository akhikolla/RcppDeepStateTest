#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List select_equal(IntegerVector x, int val1, int val2);

TEST(simPop_deepstate_test,select_equal_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector x  = RcppDeepState_IntegerVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/select_equal/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector val1(1);
  val1[0]  = RcppDeepState_int();
  qs::c_qsave(val1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/select_equal/inputs/val1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "val1 values: "<< val1 << std::endl;
  IntegerVector val2(1);
  val2[0]  = RcppDeepState_int();
  qs::c_qsave(val2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simPop/inst/testfiles/select_equal/inputs/val2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "val2 values: "<< val2 << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    select_equal(x,val1[0],val2[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
