#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector pcovcc(NumericVector a, NumericVector ap, NumericVector b, NumericVector at, NumericVector atp, NumericVector bt, int na, int nap, int nb, int period);

TEST(highfrequency_deepstate_test,pcovcc_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector a  = RcppDeepState_NumericVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a.qs";
  qs::c_qsave(a,a_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "a values: "<< a << std::endl;
  NumericVector ap  = RcppDeepState_NumericVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a.qs";
  std::string ap_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ap.qs";
  qs::c_qsave(ap,ap_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ap values: "<< ap << std::endl;
  NumericVector b  = RcppDeepState_NumericVector();
  std::string b_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_b.qs";
  qs::c_qsave(b,b_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "b values: "<< b << std::endl;
  NumericVector at  = RcppDeepState_NumericVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a.qs";
  std::string at_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_at.qs";
  qs::c_qsave(at,at_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "at values: "<< at << std::endl;
  NumericVector atp  = RcppDeepState_NumericVector();
  std::string a_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_a.qs";
  std::string at_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_at.qs";
  std::string atp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_atp.qs";
  qs::c_qsave(atp,atp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "atp values: "<< atp << std::endl;
  NumericVector bt  = RcppDeepState_NumericVector();
  std::string b_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_b.qs";
  std::string bt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_bt.qs";
  qs::c_qsave(bt,bt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "bt values: "<< bt << std::endl;
  IntegerVector na(1);
  na[0]  = RcppDeepState_int();
  std::string na_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_na.qs";
  qs::c_qsave(na,na_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "na values: "<< na << std::endl;
  IntegerVector nap(1);
  nap[0]  = RcppDeepState_int();
  std::string na_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_na.qs";
  std::string nap_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nap.qs";
  qs::c_qsave(nap,nap_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nap values: "<< nap << std::endl;
  IntegerVector nb(1);
  nb[0]  = RcppDeepState_int();
  std::string nb_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nb.qs";
  qs::c_qsave(nb,nb_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nb values: "<< nb << std::endl;
  IntegerVector period(1);
  period[0]  = RcppDeepState_int();
  std::string period_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/highfrequency/inst/testfiles/pcovcc/libFuzzer_pcovcc/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_period.qs";
  qs::c_qsave(period,period_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "period values: "<< period << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pcovcc(a,ap,b,at,atp,bt,na[0],nap[0],nb[0],period[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
