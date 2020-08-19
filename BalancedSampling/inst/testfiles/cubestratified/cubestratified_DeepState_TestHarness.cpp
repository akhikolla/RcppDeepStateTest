#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 IntegerVector cubestratified(NumericVector prob, NumericMatrix Xbal, IntegerVector integerStrata);
TEST(BalancedSampling_deepstate_test,cubestratified_test){
std::ofstream  prob_stream;
std::ofstream  Xbal_stream;
std::ofstream  integerStrata_stream;
 RInside();
 NumericVector prob = RcppDeepState_NumericVector ();
  prob_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/cubestratified/inputs/ prob");
 prob_stream<< prob;
std::cout <<"prob values: "<< prob << std::endl;
 prob_stream.close();
 NumericMatrix Xbal = RcppDeepState_NumericMatrix ();
  Xbal_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/cubestratified/inputs/ Xbal");
 Xbal_stream<< Xbal;
std::cout <<"Xbal values: "<< Xbal << std::endl;
 Xbal_stream.close();
 IntegerVector integerStrata = RcppDeepState_IntegerVector ();
  integerStrata_stream.open("/home/akhila/Documents/compileAttributescheck/BalancedSampling/inst/testfiles/cubestratified/inputs/ integerStrata");
 integerStrata_stream<< integerStrata;
std::cout <<"integerStrata values: "<< integerStrata << std::endl;
 integerStrata_stream.close();
 std::cout << "input ends" << std::endl;
 try{
cubestratified( prob, Xbal, integerStrata);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
