#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 NumericVector spm(NumericVector prob);
TEST(BalancedSampling_deepstate_test,spm_test){
std::ofstream  prob_stream;
 RInside();
 NumericVector prob = RcppDeepState_NumericVector ();
  prob_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/spm/inputs/ prob");
 prob_stream<< prob;
std::cout <<"prob values: "<< prob << std::endl;
 prob_stream.close();
 std::cout << "input ends" << std::endl;
 try{
spm( prob);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
