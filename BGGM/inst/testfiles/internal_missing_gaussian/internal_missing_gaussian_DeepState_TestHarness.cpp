#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 Rcpp::List internal_missing_gaussian(arma::mat Y, arma::mat Y_missing, arma::mat Sigma, int iter_missing);
TEST(BGGM_deepstate_test,internal_missing_gaussian_test){
std::ofstream  Y_stream;
std::ofstream  Y_missing_stream;
std::ofstream  Sigma_stream;
std::ofstream  iter_missing_stream;
RInside();
std::cout << "input starts" << std::endl;
 arma::mat Y = RcppDeepState_mat ();
  Y_stream.open("/home/akhila/Documents/compileAttributescheck/BGGM/inst/testfiles/internal_missing_gaussian/inputs/ Y");
 Y_stream<< Y;
std::cout <<"Y values: "<< Y << std::endl;
 Y_stream.close();
 arma::mat Y_missing = RcppDeepState_mat ();
  Y_missing_stream.open("/home/akhila/Documents/compileAttributescheck/BGGM/inst/testfiles/internal_missing_gaussian/inputs/ Y_missing");
 Y_missing_stream<< Y_missing;
std::cout <<"Y_missing values: "<< Y_missing << std::endl;
 Y_missing_stream.close();
 arma::mat Sigma = RcppDeepState_mat ();
  Sigma_stream.open("/home/akhila/Documents/compileAttributescheck/BGGM/inst/testfiles/internal_missing_gaussian/inputs/ Sigma");
 Sigma_stream<< Sigma;
std::cout <<"Sigma values: "<< Sigma << std::endl;
 Sigma_stream.close();
 int iter_missing = RcppDeepState_int ();
  iter_missing_stream.open("/home/akhila/Documents/compileAttributescheck/BGGM/inst/testfiles/internal_missing_gaussian/inputs/ iter_missing");
 iter_missing_stream<< iter_missing;
std::cout <<"iter_missing values: "<< iter_missing << std::endl;
 iter_missing_stream.close();
 std::cout << "input ends" << std::endl;
 try{
internal_missing_gaussian( Y, Y_missing, Sigma, iter_missing);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
