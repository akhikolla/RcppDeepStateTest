#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double Node_cost(NumericMatrix y, NumericMatrix Inv_Cov_Y, int Command);

TEST(IntegratedMRF_deepstate_test,Node_cost_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/IntegratedMRF/inst/testfiles/Node_cost/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  NumericMatrix Inv_Cov_Y  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Inv_Cov_Y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/IntegratedMRF/inst/testfiles/Node_cost/inputs/Inv_Cov_Y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Inv_Cov_Y values: "<< Inv_Cov_Y << std::endl;
  IntegerVector Command(1);
  Command[0]  = RcppDeepState_int();
  qs::c_qsave(Command,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/IntegratedMRF/inst/testfiles/Node_cost/inputs/Command.qs",
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
