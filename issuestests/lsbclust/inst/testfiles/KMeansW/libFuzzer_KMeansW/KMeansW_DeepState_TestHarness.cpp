#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List KMeansW(int nclust, IntegerVector start, NumericMatrix data, NumericVector weight, double eps, int IterMax);

TEST(lsbclust_deepstate_test,KMeansW_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector nclust(1);
  nclust[0]  = RcppDeepState_int();
  std::string nclust_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/KMeansW/libFuzzer_KMeansW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nclust.qs";
  qs::c_qsave(nclust,nclust_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nclust values: "<< nclust << std::endl;
  IntegerVector start  = RcppDeepState_IntegerVector();
  std::string start_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/KMeansW/libFuzzer_KMeansW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_start.qs";
  qs::c_qsave(start,start_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "start values: "<< start << std::endl;
  NumericMatrix data  = RcppDeepState_NumericMatrix();
  std::string data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/KMeansW/libFuzzer_KMeansW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_data.qs";
  qs::c_qsave(data,data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  NumericVector weight  = RcppDeepState_NumericVector();
  std::string weight_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/KMeansW/libFuzzer_KMeansW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_weight.qs";
  qs::c_qsave(weight,weight_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "weight values: "<< weight << std::endl;
  NumericVector eps(1);
  eps[0]  = RcppDeepState_double();
  std::string eps_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/KMeansW/libFuzzer_KMeansW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_eps.qs";
  qs::c_qsave(eps,eps_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "eps values: "<< eps << std::endl;
  IntegerVector IterMax(1);
  IterMax[0]  = RcppDeepState_int();
  std::string IterMax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/lsbclust/inst/testfiles/KMeansW/libFuzzer_KMeansW/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_IterMax.qs";
  qs::c_qsave(IterMax,IterMax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "IterMax values: "<< IterMax << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    KMeansW(nclust[0],start,data,weight,eps[0],IterMax[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
