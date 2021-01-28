#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix AllPerms(int nobj);

TEST(rankdist_deepstate_test,AllPerms_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector nobj(1);
  nobj[0]  = RcppDeepState_int();
  std::string nobj_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rankdist/inst/testfiles/AllPerms/libFuzzer_AllPerms/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nobj.qs";
  qs::c_qsave(nobj,nobj_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nobj values: "<< nobj << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    AllPerms(nobj[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
