#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector track_immobility(NumericVector t, NumericVector x, NumericVector y, double period, double tol);

TEST(amt_deepstate_test,track_immobility_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector t  = RcppDeepState_NumericVector();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_immobility/libFuzzer_track_immobility/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_t.qs";
  qs::c_qsave(t,t_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "t values: "<< t << std::endl;
  NumericVector x  = RcppDeepState_NumericVector();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_immobility/libFuzzer_track_immobility/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector y  = RcppDeepState_NumericVector();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_immobility/libFuzzer_track_immobility/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericVector period(1);
  period[0]  = RcppDeepState_double();
  std::string period_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_immobility/libFuzzer_track_immobility/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_period.qs";
  qs::c_qsave(period,period_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "period values: "<< period << std::endl;
  NumericVector tol(1);
  tol[0]  = RcppDeepState_double();
  std::string t_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_immobility/libFuzzer_track_immobility/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_t.qs";
  std::string tol_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/track_immobility/libFuzzer_track_immobility/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_tol.qs";
  qs::c_qsave(tol,tol_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "tol values: "<< tol << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    track_immobility(t,x,y,period[0],tol[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
