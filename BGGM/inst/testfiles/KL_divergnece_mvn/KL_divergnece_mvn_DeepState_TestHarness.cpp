#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double KL_divergnece_mvn(arma::mat Theta_1, arma::mat Theta_2);
TEST(BGGM_deepstate_test,KL_divergnece_mvn_test){
std::ofstream  Theta_1_stream;
std::ofstream  Theta_2_stream;
RInside();
std::cout << "input starts" << std::endl;
 arma::mat Theta_1 = RcppDeepState_mat ();
  Theta_1_stream.open("/home/akhila/Documents/compileAttributescheck/BGGM/inst/testfiles/KL_divergnece_mvn/inputs/ Theta_1");
 Theta_1_stream<< Theta_1;
std::cout <<"Theta_1 values: "<< Theta_1 << std::endl;
 Theta_1_stream.close();
 arma::mat Theta_2 = RcppDeepState_mat ();
  Theta_2_stream.open("/home/akhila/Documents/compileAttributescheck/BGGM/inst/testfiles/KL_divergnece_mvn/inputs/ Theta_2");
 Theta_2_stream<< Theta_2;
std::cout <<"Theta_2 values: "<< Theta_2 << std::endl;
 Theta_2_stream.close();
 std::cout << "input ends" << std::endl;
 try{
KL_divergnece_mvn( Theta_1, Theta_2);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
