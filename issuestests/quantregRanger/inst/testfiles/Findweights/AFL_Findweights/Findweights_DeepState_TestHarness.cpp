#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector Findweights(NumericVector ONv, NumericVector NNv, NumericVector WEv, int nobs, int nnew, int ntree, double thres, NumericVector counti, int normalise);

TEST(quantregRanger_deepstate_test,Findweights_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector ONv  = RcppDeepState_NumericVector();
  std::string ONv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/AFL_Findweights/afl_inputs/" + std::to_string(t) + "_ONv.qs";
  qs::c_qsave(ONv,ONv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ONv values: "<< ONv << std::endl;
  NumericVector NNv  = RcppDeepState_NumericVector();
  std::string NNv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/AFL_Findweights/afl_inputs/" + std::to_string(t) + "_NNv.qs";
  qs::c_qsave(NNv,NNv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NNv values: "<< NNv << std::endl;
  NumericVector WEv  = RcppDeepState_NumericVector();
  std::string WEv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/AFL_Findweights/afl_inputs/" + std::to_string(t) + "_WEv.qs";
  qs::c_qsave(WEv,WEv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WEv values: "<< WEv << std::endl;
  IntegerVector nobs(1);
  nobs[0]  = RcppDeepState_int();
  std::string nobs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/AFL_Findweights/afl_inputs/" + std::to_string(t) + "_nobs.qs";
  qs::c_qsave(nobs,nobs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nobs values: "<< nobs << std::endl;
  IntegerVector nnew(1);
  nnew[0]  = RcppDeepState_int();
  std::string nnew_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/AFL_Findweights/afl_inputs/" + std::to_string(t) + "_nnew.qs";
  qs::c_qsave(nnew,nnew_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nnew values: "<< nnew << std::endl;
  IntegerVector ntree(1);
  ntree[0]  = RcppDeepState_int();
  std::string ntree_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/AFL_Findweights/afl_inputs/" + std::to_string(t) + "_ntree.qs";
  qs::c_qsave(ntree,ntree_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ntree values: "<< ntree << std::endl;
  NumericVector thres(1);
  thres[0]  = RcppDeepState_double();
  std::string thres_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/AFL_Findweights/afl_inputs/" + std::to_string(t) + "_thres.qs";
  qs::c_qsave(thres,thres_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "thres values: "<< thres << std::endl;
  NumericVector counti  = RcppDeepState_NumericVector();
  std::string counti_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/AFL_Findweights/afl_inputs/" + std::to_string(t) + "_counti.qs";
  qs::c_qsave(counti,counti_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "counti values: "<< counti << std::endl;
  IntegerVector normalise(1);
  normalise[0]  = RcppDeepState_int();
  std::string normalise_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/AFL_Findweights/afl_inputs/" + std::to_string(t) + "_normalise.qs";
  qs::c_qsave(normalise,normalise_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "normalise values: "<< normalise << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Findweights(ONv,NNv,WEv,nobs[0],nnew[0],ntree[0],thres[0],counti,normalise[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
