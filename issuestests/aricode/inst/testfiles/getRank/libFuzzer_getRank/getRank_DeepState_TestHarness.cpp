#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List getRank(IntegerVector classi);

TEST(aricode_deepstate_test,getRank_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector classi  = RcppDeepState_IntegerVector();
  std::string classi_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aricode/inst/testfiles/getRank/libFuzzer_getRank/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_classi.qs";
  qs::c_qsave(classi,classi_t,
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
