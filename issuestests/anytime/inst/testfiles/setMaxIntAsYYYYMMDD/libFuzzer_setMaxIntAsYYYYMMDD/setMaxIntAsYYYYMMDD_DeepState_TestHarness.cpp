#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

void setMaxIntAsYYYYMMDD(const int val);

TEST(anytime_deepstate_test,setMaxIntAsYYYYMMDD_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector val(1);
  val[0]  = RcppDeepState_int();
  std::string val_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/anytime/inst/testfiles/setMaxIntAsYYYYMMDD/libFuzzer_setMaxIntAsYYYYMMDD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_val.qs";
  qs::c_qsave(val,val_t,
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
