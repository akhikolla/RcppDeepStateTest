#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix ComputeMeans(IntegerVector cm, NumericMatrix data, NumericVector weight, int nclust);

TEST(lsbclust_deepstate_test,ComputeMeans_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector cm  = RcppDeepState_IntegerVector();
  std::string cm_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/ComputeMeans/libFuzzer_ComputeMeans/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cm.qs";
  qs::c_qsave(cm,cm_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cm values: "<< cm << std::endl;
  NumericMatrix data  = RcppDeepState_NumericMatrix();
  std::string data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/ComputeMeans/libFuzzer_ComputeMeans/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_data.qs";
  qs::c_qsave(data,data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  NumericVector weight  = RcppDeepState_NumericVector();
  std::string weight_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/ComputeMeans/libFuzzer_ComputeMeans/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_weight.qs";
  qs::c_qsave(weight,weight_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weight values: "<< weight << std::endl;
  IntegerVector nclust(1);
  nclust[0]  = RcppDeepState_int();
  std::string nclust_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/ComputeMeans/libFuzzer_ComputeMeans/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nclust.qs";
  qs::c_qsave(nclust,nclust_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nclust values: "<< nclust << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ComputeMeans(cm,data,weight,nclust[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
