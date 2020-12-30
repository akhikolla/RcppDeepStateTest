#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

arma::vec log_const_vmcos_all(arma::mat par_mat, arma::mat uni_rand);

TEST(BAMBI_deepstate_test,log_const_vmcos_all_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  std::ofstream par_mat_stream;
  arma::mat par_mat  = RcppDeepState_mat();
  par_mat_stream.open("/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/log_const_vmcos_all/inputs/par_mat");
  par_mat_stream << par_mat;
  std::cout << "par_mat values: "<< par_mat << std::endl;
  par_mat_stream.close();
  std::ofstream uni_rand_stream;
  arma::mat uni_rand  = RcppDeepState_mat();
  uni_rand_stream.open("/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/log_const_vmcos_all/inputs/uni_rand");
  uni_rand_stream << uni_rand;
  std::cout << "uni_rand values: "<< uni_rand << std::endl;
  uni_rand_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    log_const_vmcos_all(par_mat,uni_rand);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
