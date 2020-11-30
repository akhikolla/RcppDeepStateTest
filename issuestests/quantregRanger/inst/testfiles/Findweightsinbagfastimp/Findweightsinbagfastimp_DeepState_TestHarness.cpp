#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List Findweightsinbagfastimp(NumericVector ONv, NumericVector ONvp, NumericVector OrdNv, NumericVector filterednodes, IntegerVector index, IntegerVector newindex, IntegerVector inbag, NumericVector WEv, NumericVector WEvp, int npred, int nobs, int ntree, double thres, int l, IntegerVector countbreak);

TEST(quantregRanger_deepstate_test,Findweightsinbagfastimp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector ONv  = RcppDeepState_NumericVector();
  qs::c_qsave(ONv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/ONv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ONv values: "<< ONv << std::endl;
  NumericVector ONvp  = RcppDeepState_NumericVector();
  qs::c_qsave(ONvp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/ONvp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ONvp values: "<< ONvp << std::endl;
  NumericVector OrdNv  = RcppDeepState_NumericVector();
  qs::c_qsave(OrdNv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/OrdNv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "OrdNv values: "<< OrdNv << std::endl;
  NumericVector filterednodes  = RcppDeepState_NumericVector();
  qs::c_qsave(filterednodes,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/filterednodes.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "filterednodes values: "<< filterednodes << std::endl;
  IntegerVector index  = RcppDeepState_IntegerVector();
  qs::c_qsave(index,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/index.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "index values: "<< index << std::endl;
  IntegerVector newindex  = RcppDeepState_IntegerVector();
  qs::c_qsave(newindex,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/newindex.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "newindex values: "<< newindex << std::endl;
  IntegerVector inbag  = RcppDeepState_IntegerVector();
  qs::c_qsave(inbag,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/inbag.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "inbag values: "<< inbag << std::endl;
  NumericVector WEv  = RcppDeepState_NumericVector();
  qs::c_qsave(WEv,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/WEv.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WEv values: "<< WEv << std::endl;
  NumericVector WEvp  = RcppDeepState_NumericVector();
  qs::c_qsave(WEvp,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/WEvp.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "WEvp values: "<< WEvp << std::endl;
  IntegerVector npred(1);
  npred[0]  = RcppDeepState_int();
  qs::c_qsave(npred,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/npred.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "npred values: "<< npred << std::endl;
  IntegerVector nobs(1);
  nobs[0]  = RcppDeepState_int();
  qs::c_qsave(nobs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/nobs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nobs values: "<< nobs << std::endl;
  IntegerVector ntree(1);
  ntree[0]  = RcppDeepState_int();
  qs::c_qsave(ntree,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/ntree.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ntree values: "<< ntree << std::endl;
  NumericVector thres(1);
  thres[0]  = RcppDeepState_double();
  qs::c_qsave(thres,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/thres.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "thres values: "<< thres << std::endl;
  IntegerVector l(1);
  l[0]  = RcppDeepState_int();
  qs::c_qsave(l,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/l.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "l values: "<< l << std::endl;
  IntegerVector countbreak  = RcppDeepState_IntegerVector();
  qs::c_qsave(countbreak,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/quantregRanger/inst/testfiles/Findweightsinbagfastimp/inputs/countbreak.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "countbreak values: "<< countbreak << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Findweightsinbagfastimp(ONv,ONvp,OrdNv,filterednodes,index,newindex,inbag,WEv,WEvp,npred[0],nobs[0],ntree[0],thres[0],l[0],countbreak);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
