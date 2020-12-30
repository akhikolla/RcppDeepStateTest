#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List duration_viterbi(NumericVector aa_sample, NumericVector pipar, NumericMatrix tpmpar, NumericMatrix od, NumericMatrix params);

TEST(signalHsmm_deepstate_test,duration_viterbi_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector aa_sample  = RcppDeepState_NumericVector();
  std::string aa_sample_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/signalHsmm/inst/testfiles/duration_viterbi/AFL_duration_viterbi/afl_inputs/" + std::to_string(t) + "_aa_sample.qs";
  qs::c_qsave(aa_sample,aa_sample_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "aa_sample values: "<< aa_sample << std::endl;
  NumericVector pipar  = RcppDeepState_NumericVector();
  std::string pipar_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/signalHsmm/inst/testfiles/duration_viterbi/AFL_duration_viterbi/afl_inputs/" + std::to_string(t) + "_pipar.qs";
  qs::c_qsave(pipar,pipar_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pipar values: "<< pipar << std::endl;
  NumericMatrix tpmpar  = RcppDeepState_NumericMatrix();
  std::string tpmpar_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/signalHsmm/inst/testfiles/duration_viterbi/AFL_duration_viterbi/afl_inputs/" + std::to_string(t) + "_tpmpar.qs";
  qs::c_qsave(tpmpar,tpmpar_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tpmpar values: "<< tpmpar << std::endl;
  NumericMatrix od  = RcppDeepState_NumericMatrix();
  std::string od_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/signalHsmm/inst/testfiles/duration_viterbi/AFL_duration_viterbi/afl_inputs/" + std::to_string(t) + "_od.qs";
  qs::c_qsave(od,od_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "od values: "<< od << std::endl;
  NumericMatrix params  = RcppDeepState_NumericMatrix();
  std::string params_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/signalHsmm/inst/testfiles/duration_viterbi/AFL_duration_viterbi/afl_inputs/" + std::to_string(t) + "_params.qs";
  qs::c_qsave(params,params_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "params values: "<< params << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    duration_viterbi(aa_sample,pipar,tpmpar,od,params);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
