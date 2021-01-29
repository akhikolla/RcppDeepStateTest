#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double ROI(int ncases_nor, int ncases_abn, int max_nl, NumericVector n_les, NumericMatrix nl, NumericMatrix ll);

TEST(RJafroc_deepstate_test,ROI_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector ncases_nor(1);
  ncases_nor[0]  = RcppDeepState_int();
  std::string ncases_nor_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ROI/libFuzzer_ROI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ncases_nor.qs";
  qs::c_qsave(ncases_nor,ncases_nor_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ncases_nor values: "<< ncases_nor << std::endl;
  IntegerVector ncases_abn(1);
  ncases_abn[0]  = RcppDeepState_int();
  std::string ncases_abn_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ROI/libFuzzer_ROI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ncases_abn.qs";
  qs::c_qsave(ncases_abn,ncases_abn_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ncases_abn values: "<< ncases_abn << std::endl;
  IntegerVector max_nl(1);
  max_nl[0]  = RcppDeepState_int();
  std::string max_nl_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ROI/libFuzzer_ROI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_max_nl.qs";
  qs::c_qsave(max_nl,max_nl_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_nl values: "<< max_nl << std::endl;
  NumericVector n_les  = RcppDeepState_NumericVector();
  std::string n_les_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ROI/libFuzzer_ROI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_les.qs";
  qs::c_qsave(n_les,n_les_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_les values: "<< n_les << std::endl;
  NumericMatrix nl  = RcppDeepState_NumericMatrix();
  std::string nl_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ROI/libFuzzer_ROI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nl.qs";
  qs::c_qsave(nl,nl_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nl values: "<< nl << std::endl;
  NumericMatrix ll  = RcppDeepState_NumericMatrix();
  std::string ll_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/RJafroc/inst/testfiles/ROI/libFuzzer_ROI/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ll.qs";
  qs::c_qsave(ll,ll_t,
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
