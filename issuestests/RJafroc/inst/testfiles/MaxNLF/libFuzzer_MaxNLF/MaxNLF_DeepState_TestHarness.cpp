#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double MaxNLF(NumericMatrix nl, NumericMatrix ll, NumericVector n_lesions_per_image, NumericVector max_cases, int max_nl, int max_ll);

TEST(RJafroc_deepstate_test,MaxNLF_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix nl  = RcppDeepState_NumericMatrix();
  std::string nl_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/MaxNLF/libFuzzer_MaxNLF/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nl.qs";
  qs::c_qsave(nl,nl_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nl values: "<< nl << std::endl;
  NumericMatrix ll  = RcppDeepState_NumericMatrix();
  std::string ll_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/MaxNLF/libFuzzer_MaxNLF/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ll.qs";
  qs::c_qsave(ll,ll_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ll values: "<< ll << std::endl;
  NumericVector n_lesions_per_image  = RcppDeepState_NumericVector();
  std::string n_lesions_per_image_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/MaxNLF/libFuzzer_MaxNLF/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_lesions_per_image.qs";
  qs::c_qsave(n_lesions_per_image,n_lesions_per_image_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_lesions_per_image values: "<< n_lesions_per_image << std::endl;
  NumericVector max_cases  = RcppDeepState_NumericVector();
  std::string max_cases_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/MaxNLF/libFuzzer_MaxNLF/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_max_cases.qs";
  qs::c_qsave(max_cases,max_cases_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_cases values: "<< max_cases << std::endl;
  IntegerVector max_nl(1);
  max_nl[0]  = RcppDeepState_int();
  std::string max_nl_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/MaxNLF/libFuzzer_MaxNLF/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_max_nl.qs";
  qs::c_qsave(max_nl,max_nl_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_nl values: "<< max_nl << std::endl;
  IntegerVector max_ll(1);
  max_ll[0]  = RcppDeepState_int();
  std::string max_ll_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/MaxNLF/libFuzzer_MaxNLF/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_max_ll.qs";
  qs::c_qsave(max_ll,max_ll_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_ll values: "<< max_ll << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    MaxNLF(nl,ll,n_lesions_per_image,max_cases,max_nl[0],max_ll[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
