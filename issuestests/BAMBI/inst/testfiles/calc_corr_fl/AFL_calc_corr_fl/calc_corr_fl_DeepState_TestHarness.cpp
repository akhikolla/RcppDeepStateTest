#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

double calc_corr_fl(arma::mat samp_mat);

TEST(BAMBI_deepstate_test,calc_corr_fl_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  std::ofstream samp_mat_stream;
  arma::mat samp_mat  = RcppDeepState_mat();
  samp_mat_stream.open("/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/calc_corr_fl/inputs/samp_mat");
  samp_mat_stream << samp_mat;
  std::cout << "samp_mat values: "<< samp_mat << std::endl;
  samp_mat_stream.close();
  std::cout << "input ends" << std::endl;
  try{
    calc_corr_fl(samp_mat);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
