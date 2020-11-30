#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::vec rowVars(arma::mat mat_in);

TEST(BAMBI_deepstate_test,rowVars_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  std::ofstream mat_in_stream;
  arma::mat mat_in  = RcppDeepState_mat();
  mat_in_stream.open("/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/rowVars/inputs/mat_in");
  mat_in_stream << mat_in;
  std::cout << "mat_in values: "<< mat_in << std::endl;
  mat_in_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    rowVars(mat_in);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
