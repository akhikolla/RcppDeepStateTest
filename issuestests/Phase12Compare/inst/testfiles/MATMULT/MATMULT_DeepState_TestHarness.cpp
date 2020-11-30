#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::mat MATMULT(arma::mat X, arma::mat Y);

TEST(Phase12Compare_deepstate_test,MATMULT_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  std::ofstream X_stream;
  arma::mat X  = RcppDeepState_mat();
  X_stream.open("/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Phase12Compare/inst/testfiles/MATMULT/inputs/X");
  X_stream << X;
  std::cout << "X values: "<< X << std::endl;
  X_stream.close();
  std::ofstream Y_stream;
  arma::mat Y  = RcppDeepState_mat();
  Y_stream.open("/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Phase12Compare/inst/testfiles/MATMULT/inputs/Y");
  Y_stream << Y;
  std::cout << "Y values: "<< Y << std::endl;
  Y_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    MATMULT(X,Y);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
