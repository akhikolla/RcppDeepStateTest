#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::NumericVector Findweightsfast(NumericVector OrdNv, NumericVector NNv, NumericVector filterednodes, IntegerVector index, IntegerVector newindex, NumericVector WEv, int nobs, int nnew, int ntree, double thres, int l);

TEST(quantregRanger_deepstate_test,Findweightsfast_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector OrdNv  = RcppDeepState_NumericVector();
  qs::c_qsave(OrdNv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/inputs/OrdNv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "OrdNv values: "<< OrdNv << std::endl;
  NumericVector NNv  = RcppDeepState_NumericVector();
  qs::c_qsave(NNv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/inputs/NNv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NNv values: "<< NNv << std::endl;
  NumericVector filterednodes  = RcppDeepState_NumericVector();
  qs::c_qsave(filterednodes,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/inputs/filterednodes.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "filterednodes values: "<< filterednodes << std::endl;
  IntegerVector index  = RcppDeepState_IntegerVector();
  qs::c_qsave(index,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/inputs/index.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "index values: "<< index << std::endl;
  IntegerVector newindex  = RcppDeepState_IntegerVector();
  qs::c_qsave(newindex,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/inputs/newindex.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "newindex values: "<< newindex << std::endl;
  NumericVector WEv  = RcppDeepState_NumericVector();
  qs::c_qsave(WEv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/inputs/WEv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WEv values: "<< WEv << std::endl;
  IntegerVector nobs(1);
  nobs[0]  = RcppDeepState_int();
  qs::c_qsave(nobs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/inputs/nobs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nobs values: "<< nobs << std::endl;
  IntegerVector nnew(1);
  nnew[0]  = RcppDeepState_int();
  qs::c_qsave(nnew,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/inputs/nnew.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nnew values: "<< nnew << std::endl;
  IntegerVector ntree(1);
  ntree[0]  = RcppDeepState_int();
  qs::c_qsave(ntree,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/inputs/ntree.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ntree values: "<< ntree << std::endl;
  NumericVector thres(1);
  thres[0]  = RcppDeepState_double();
  qs::c_qsave(thres,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/inputs/thres.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "thres values: "<< thres << std::endl;
  IntegerVector l(1);
  l[0]  = RcppDeepState_int();
  qs::c_qsave(l,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsfast/inputs/l.qs",
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
