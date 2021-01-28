#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector Findweightsinbag(NumericVector ONv, IntegerVector inbag, NumericVector WEv, int nobs, int nnew, int ntree, double thres, NumericVector counti, int normalise);

TEST(quantregRanger_deepstate_test,Findweightsinbag_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector ONv  = RcppDeepState_NumericVector();
  std::string ONv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbag/libFuzzer_Findweightsinbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ONv.qs";
  qs::c_qsave(ONv,ONv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ONv values: "<< ONv << std::endl;
  IntegerVector inbag  = RcppDeepState_IntegerVector();
  std::string inbag_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbag/libFuzzer_Findweightsinbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_inbag.qs";
  qs::c_qsave(inbag,inbag_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "inbag values: "<< inbag << std::endl;
  NumericVector WEv  = RcppDeepState_NumericVector();
  std::string WEv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbag/libFuzzer_Findweightsinbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_WEv.qs";
  qs::c_qsave(WEv,WEv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WEv values: "<< WEv << std::endl;
  IntegerVector nobs(1);
  nobs[0]  = RcppDeepState_int();
  std::string nobs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbag/libFuzzer_Findweightsinbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nobs.qs";
  qs::c_qsave(nobs,nobs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nobs values: "<< nobs << std::endl;
  IntegerVector nnew(1);
  nnew[0]  = RcppDeepState_int();
  std::string nnew_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbag/libFuzzer_Findweightsinbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nnew.qs";
  qs::c_qsave(nnew,nnew_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nnew values: "<< nnew << std::endl;
  IntegerVector ntree(1);
  ntree[0]  = RcppDeepState_int();
  std::string ntree_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbag/libFuzzer_Findweightsinbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ntree.qs";
  qs::c_qsave(ntree,ntree_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ntree values: "<< ntree << std::endl;
  NumericVector thres(1);
  thres[0]  = RcppDeepState_double();
  std::string thres_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbag/libFuzzer_Findweightsinbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_thres.qs";
  qs::c_qsave(thres,thres_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "thres values: "<< thres << std::endl;
  NumericVector counti  = RcppDeepState_NumericVector();
  std::string counti_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbag/libFuzzer_Findweightsinbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_counti.qs";
  qs::c_qsave(counti,counti_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "counti values: "<< counti << std::endl;
  IntegerVector normalise(1);
  normalise[0]  = RcppDeepState_int();
  std::string normalise_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbag/libFuzzer_Findweightsinbag/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_normalise.qs";
  qs::c_qsave(normalise,normalise_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "normalise values: "<< normalise << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Findweightsinbag(ONv,inbag,WEv,nobs[0],nnew[0],ntree[0],thres[0],counti,normalise[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
