#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double pnct(const double x, const double df, const double ncp);

TEST(exceedProb_deepstate_test,pnct_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector x(1);
  x[0]  = RcppDeepState_double();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/exceedProb/inst/testfiles/pnct/libFuzzer_pnct/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericVector df(1);
  df[0]  = RcppDeepState_double();
  std::string df_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/exceedProb/inst/testfiles/pnct/libFuzzer_pnct/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_df.qs";
  qs::c_qsave(df,df_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "df values: "<< df << std::endl;
  NumericVector ncp(1);
  ncp[0]  = RcppDeepState_double();
  std::string ncp_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/exceedProb/inst/testfiles/pnct/libFuzzer_pnct/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ncp.qs";
  qs::c_qsave(ncp,ncp_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ncp values: "<< ncp << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    pnct(x[0],df[0],ncp[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
