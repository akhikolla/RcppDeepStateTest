#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector Findweightsfast(NumericVector OrdNv, NumericVector NNv, NumericVector filterednodes, IntegerVector index, IntegerVector newindex, NumericVector WEv, int nobs, int nnew, int ntree, double thres, int l);

TEST(quantregRanger_deepstate_test,Findweightsfast_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector OrdNv  = RcppDeepState_NumericVector();
  std::string OrdNv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/libFuzzer_Findweightsfast/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_OrdNv.qs";
  qs::c_qsave(OrdNv,OrdNv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "OrdNv values: "<< OrdNv << std::endl;
  NumericVector NNv  = RcppDeepState_NumericVector();
  std::string NNv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/libFuzzer_Findweightsfast/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_NNv.qs";
  qs::c_qsave(NNv,NNv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NNv values: "<< NNv << std::endl;
  NumericVector filterednodes  = RcppDeepState_NumericVector();
  std::string filterednodes_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/libFuzzer_Findweightsfast/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_filterednodes.qs";
  qs::c_qsave(filterednodes,filterednodes_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "filterednodes values: "<< filterednodes << std::endl;
  IntegerVector index  = RcppDeepState_IntegerVector();
  std::string index_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/libFuzzer_Findweightsfast/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_index.qs";
  qs::c_qsave(index,index_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "index values: "<< index << std::endl;
  IntegerVector newindex  = RcppDeepState_IntegerVector();
  std::string newindex_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/libFuzzer_Findweightsfast/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_newindex.qs";
  qs::c_qsave(newindex,newindex_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "newindex values: "<< newindex << std::endl;
  NumericVector WEv  = RcppDeepState_NumericVector();
  std::string WEv_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/libFuzzer_Findweightsfast/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_WEv.qs";
  qs::c_qsave(WEv,WEv_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WEv values: "<< WEv << std::endl;
  IntegerVector nobs(1);
  nobs[0]  = RcppDeepState_int();
  std::string nobs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/libFuzzer_Findweightsfast/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nobs.qs";
  qs::c_qsave(nobs,nobs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nobs values: "<< nobs << std::endl;
  IntegerVector nnew(1);
  nnew[0]  = RcppDeepState_int();
  std::string nnew_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/libFuzzer_Findweightsfast/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nnew.qs";
  qs::c_qsave(nnew,nnew_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nnew values: "<< nnew << std::endl;
  IntegerVector ntree(1);
  ntree[0]  = RcppDeepState_int();
  std::string ntree_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/libFuzzer_Findweightsfast/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ntree.qs";
  qs::c_qsave(ntree,ntree_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ntree values: "<< ntree << std::endl;
  NumericVector thres(1);
  thres[0]  = RcppDeepState_double();
  std::string thres_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/libFuzzer_Findweightsfast/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_thres.qs";
  qs::c_qsave(thres,thres_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "thres values: "<< thres << std::endl;
  IntegerVector l(1);
  l[0]  = RcppDeepState_int();
  std::string l_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/libFuzzer_Findweightsfast/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_l.qs";
  qs::c_qsave(l,l_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "l values: "<< l << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Findweightsfast(OrdNv,NNv,filterednodes,index,newindex,WEv,nobs[0],nnew[0],ntree[0],thres[0],l[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
