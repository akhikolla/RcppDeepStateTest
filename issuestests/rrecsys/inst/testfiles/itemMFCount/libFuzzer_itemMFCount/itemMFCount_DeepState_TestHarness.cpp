#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector itemMFCount(NumericMatrix sim_index, NumericVector user_vector, double pt);

TEST(rrecsys_deepstate_test,itemMFCount_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix sim_index  = RcppDeepState_NumericMatrix();
  std::string sim_index_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/itemMFCount/libFuzzer_itemMFCount/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_sim_index.qs";
  qs::c_qsave(sim_index,sim_index_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sim_index values: "<< sim_index << std::endl;
  NumericVector user_vector  = RcppDeepState_NumericVector();
  std::string user_vector_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/itemMFCount/libFuzzer_itemMFCount/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_user_vector.qs";
  qs::c_qsave(user_vector,user_vector_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "user_vector values: "<< user_vector << std::endl;
  NumericVector pt(1);
  pt[0]  = RcppDeepState_double();
  std::string pt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/itemMFCount/libFuzzer_itemMFCount/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_pt.qs";
  qs::c_qsave(pt,pt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pt values: "<< pt << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    itemMFCount(sim_index,user_vector,pt[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
