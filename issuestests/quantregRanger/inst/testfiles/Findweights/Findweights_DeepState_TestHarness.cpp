#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector Findweights(NumericVector ONv, NumericVector NNv, NumericVector WEv, int nobs, int nnew, int ntree, double thres, NumericVector counti, int normalise);

TEST(quantregRanger_deepstate_test,Findweights_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector ONv  = RcppDeepState_NumericVector();
  qs::c_qsave(ONv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/inputs/ONv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ONv values: "<< ONv << std::endl;
  NumericVector NNv  = RcppDeepState_NumericVector();
  qs::c_qsave(NNv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/inputs/NNv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NNv values: "<< NNv << std::endl;
  NumericVector WEv  = RcppDeepState_NumericVector();
  qs::c_qsave(WEv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/inputs/WEv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WEv values: "<< WEv << std::endl;
  IntegerVector nobs(1);
  nobs[0]  = RcppDeepState_int();
  qs::c_qsave(nobs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/inputs/nobs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nobs values: "<< nobs << std::endl;
  IntegerVector nnew(1);
  nnew[0]  = RcppDeepState_int();
  qs::c_qsave(nnew,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/inputs/nnew.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nnew values: "<< nnew << std::endl;
  IntegerVector ntree(1);
  ntree[0]  = RcppDeepState_int();
  qs::c_qsave(ntree,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/inputs/ntree.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ntree values: "<< ntree << std::endl;
  NumericVector thres(1);
  thres[0]  = RcppDeepState_double();
  qs::c_qsave(thres,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/inputs/thres.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "thres values: "<< thres << std::endl;
  NumericVector counti  = RcppDeepState_NumericVector();
  qs::c_qsave(counti,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/inputs/counti.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "counti values: "<< counti << std::endl;
  IntegerVector normalise(1);
  normalise[0]  = RcppDeepState_int();
  qs::c_qsave(normalise,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweights/inputs/normalise.qs",
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
