#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double ROI(int ncases_nor, int ncases_abn, int max_nl, NumericVector n_les, NumericMatrix nl, NumericMatrix ll);

TEST(RJafroc_deepstate_test,ROI_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector ncases_nor(1);
  ncases_nor[0]  = RcppDeepState_int();
  qs::c_qsave(ncases_nor,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ROI/inputs/ncases_nor.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ncases_nor values: "<< ncases_nor << std::endl;
  IntegerVector ncases_abn(1);
  ncases_abn[0]  = RcppDeepState_int();
  qs::c_qsave(ncases_abn,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ROI/inputs/ncases_abn.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ncases_abn values: "<< ncases_abn << std::endl;
  IntegerVector max_nl(1);
  max_nl[0]  = RcppDeepState_int();
  qs::c_qsave(max_nl,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ROI/inputs/max_nl.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_nl values: "<< max_nl << std::endl;
  NumericVector n_les  = RcppDeepState_NumericVector();
  qs::c_qsave(n_les,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ROI/inputs/n_les.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_les values: "<< n_les << std::endl;
  NumericMatrix nl  = RcppDeepState_NumericMatrix();
  qs::c_qsave(nl,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ROI/inputs/nl.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nl values: "<< nl << std::endl;
  NumericMatrix ll  = RcppDeepState_NumericMatrix();
  qs::c_qsave(ll,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ROI/inputs/ll.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ll values: "<< ll << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ROI(ncases_nor[0],ncases_abn[0],max_nl[0],n_les,nl,ll);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
