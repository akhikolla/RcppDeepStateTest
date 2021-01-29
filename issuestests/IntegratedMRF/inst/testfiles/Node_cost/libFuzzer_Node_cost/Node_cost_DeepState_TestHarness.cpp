#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double Node_cost(NumericMatrix y, NumericMatrix Inv_Cov_Y, int Command);

TEST(IntegratedMRF_deepstate_test,Node_cost_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix y  = RcppDeepState_NumericMatrix();
  std::string y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/IntegratedMRF/inst/testfiles/Node_cost/libFuzzer_Node_cost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_y.qs";
  qs::c_qsave(y,y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericMatrix Inv_Cov_Y  = RcppDeepState_NumericMatrix();
  std::string Inv_Cov_Y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/IntegratedMRF/inst/testfiles/Node_cost/libFuzzer_Node_cost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Inv_Cov_Y.qs";
  qs::c_qsave(Inv_Cov_Y,Inv_Cov_Y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Inv_Cov_Y values: "<< Inv_Cov_Y << std::endl;
  IntegerVector Command(1);
  Command[0]  = RcppDeepState_int();
  std::string Command_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/IntegratedMRF/inst/testfiles/Node_cost/libFuzzer_Node_cost/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_Command.qs";
  qs::c_qsave(Command,Command_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Command values: "<< Command << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    Node_cost(y,Inv_Cov_Y,Command[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
