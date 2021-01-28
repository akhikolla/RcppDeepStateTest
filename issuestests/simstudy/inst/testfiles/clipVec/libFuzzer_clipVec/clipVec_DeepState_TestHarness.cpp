#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerVector clipVec(IntegerVector id, IntegerVector seq, IntegerVector event);

TEST(simstudy_deepstate_test,clipVec_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector id  = RcppDeepState_IntegerVector();
  std::string id_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/clipVec/libFuzzer_clipVec/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_id.qs";
  qs::c_qsave(id,id_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "id values: "<< id << std::endl;
  IntegerVector seq  = RcppDeepState_IntegerVector();
  std::string seq_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/clipVec/libFuzzer_clipVec/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_seq.qs";
  qs::c_qsave(seq,seq_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seq values: "<< seq << std::endl;
  IntegerVector event  = RcppDeepState_IntegerVector();
  std::string event_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/clipVec/libFuzzer_clipVec/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_event.qs";
  qs::c_qsave(event,event_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "event values: "<< event << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    clipVec(id,seq,event);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
