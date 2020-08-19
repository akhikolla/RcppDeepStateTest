#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double calc_corr_tau_2(arma::mat samp_mat);
TEST(BAMBI_deepstate_test,calc_corr_tau_2_test){
std::ofstream  samp_mat_stream;
 RInside();
 arma::mat samp_mat = RcppDeepState_mat ();
  samp_mat_stream.open("/home/akhila/Documents/compileAttributescheck/BAMBI/inst/testfiles/calc_corr_tau_2/inputs/ samp_mat");
 samp_mat_stream<< samp_mat;
std::cout <<"samp_mat values: "<< samp_mat << std::endl;
 samp_mat_stream.close();
 std::cout << "input ends" << std::endl;
 try{
calc_corr_tau_2( samp_mat);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
