#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List ViterbiD(IntegerVector x, IntegerVector y, int type, double d, double e, NumericMatrix S, IntegerVector windowspace, double offset);

TEST(aphid_deepstate_test,ViterbiD_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector x  = RcppDeepState_IntegerVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/libFuzzer_ViterbiD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector y  = RcppDeepState_IntegerVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/libFuzzer_ViterbiD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  IntegerVector type(1);
  type[0]  = RcppDeepState_int();
  std::string type_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/libFuzzer_ViterbiD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_type.qs";
  qs::c_qsave(type,type_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "type values: "<< type << std::endl;
  NumericVector d(1);
  d[0]  = RcppDeepState_double();
  std::string d_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/libFuzzer_ViterbiD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_d.qs";
  qs::c_qsave(d,d_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "d values: "<< d << std::endl;
  NumericVector e(1);
  e[0]  = RcppDeepState_double();
  std::string e_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/libFuzzer_ViterbiD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_e.qs";
  qs::c_qsave(e,e_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "e values: "<< e << std::endl;
  NumericMatrix S  = RcppDeepState_NumericMatrix();
  std::string S_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/libFuzzer_ViterbiD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_S.qs";
  qs::c_qsave(S,S_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "S values: "<< S << std::endl;
  IntegerVector windowspace  = RcppDeepState_IntegerVector();
  std::string windowspace_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/libFuzzer_ViterbiD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_windowspace.qs";
  qs::c_qsave(windowspace,windowspace_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "windowspace values: "<< windowspace << std::endl;
  NumericVector offset(1);
  offset[0]  = RcppDeepState_double();
  std::string offset_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/libFuzzer_ViterbiD/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_offset.qs";
  qs::c_qsave(offset,offset_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "offset values: "<< offset << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ViterbiD(x,y,type[0],d[0],e[0],S,windowspace,offset[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
