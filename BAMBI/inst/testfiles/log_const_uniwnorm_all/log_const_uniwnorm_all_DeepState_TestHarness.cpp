#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 arma::vec log_const_uniwnorm_all(arma::mat par_mat);
TEST(BAMBI_deepstate_test,log_const_uniwnorm_all_test){
std::ofstream  par_mat_stream;
 RInside();
 arma::mat par_mat = RcppDeepState_mat ();
  par_mat_stream.open("/home/akhila/Documents/compileAttributescheck/BAMBI/inst/testfiles/log_const_uniwnorm_all/inputs/ par_mat");
 par_mat_stream<< par_mat;
std::cout <<"par_mat values: "<< par_mat << std::endl;
 par_mat_stream.close();
 std::cout << "input ends" << std::endl;
 try{
log_const_uniwnorm_all( par_mat);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
