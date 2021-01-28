#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::List cpp_wkt_translate_wksxp(CharacterVector wkt, int includeZ, int includeM, int includeSRID);

TEST(wk_deepstate_test,cpp_wkt_translate_wksxp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  CharacterVector wkt  = RcppDeepState_CharacterVector();
  std::string wkt_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wk/inst/testfiles/cpp_wkt_translate_wksxp/libFuzzer_cpp_wkt_translate_wksxp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_wkt.qs";
  qs::c_qsave(wkt,wkt_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "wkt values: "<< wkt << std::endl;
  IntegerVector includeZ(1);
  includeZ[0]  = RcppDeepState_int();
  std::string includeZ_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wk/inst/testfiles/cpp_wkt_translate_wksxp/libFuzzer_cpp_wkt_translate_wksxp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_includeZ.qs";
  qs::c_qsave(includeZ,includeZ_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "includeZ values: "<< includeZ << std::endl;
  IntegerVector includeM(1);
  includeM[0]  = RcppDeepState_int();
  std::string includeM_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wk/inst/testfiles/cpp_wkt_translate_wksxp/libFuzzer_cpp_wkt_translate_wksxp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_includeM.qs";
  qs::c_qsave(includeM,includeM_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "includeM values: "<< includeM << std::endl;
  IntegerVector includeSRID(1);
  includeSRID[0]  = RcppDeepState_int();
  std::string includeSRID_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/wk/inst/testfiles/cpp_wkt_translate_wksxp/libFuzzer_cpp_wkt_translate_wksxp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_includeSRID.qs";
  qs::c_qsave(includeSRID,includeSRID_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "includeSRID values: "<< includeSRID << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    cpp_wkt_translate_wksxp(wkt,includeZ[0],includeM[0],includeSRID[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
