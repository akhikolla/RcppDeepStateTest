#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void setMaxIntAsYYYYMMDD(const int val);

TEST(anytime_deepstate_test,setMaxIntAsYYYYMMDD_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector val(1);
  val[0]  = RcppDeepState_int();
  qs::c_qsave(val,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/anytime/inst/testfiles/setMaxIntAsYYYYMMDD/inputs/val.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "val values: "<< val << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    setMaxIntAsYYYYMMDD(val[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
