#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double likelihood_function2(NumericVector y_temp, NumericMatrix treetable_temp, NumericMatrix obs_to_nodes_temp, double a, double mu, double nu, double lambda);
TEST(bartBMA_deepstate_test,likelihood_function2_test){
std::ofstream  y_temp_stream;
std::ofstream  treetable_temp_stream;
std::ofstream  obs_to_nodes_temp_stream;
std::ofstream  a_stream;
std::ofstream  mu_stream;
std::ofstream  nu_stream;
std::ofstream  lambda_stream;
 RInside();
 NumericVector y_temp = RcppDeepState_NumericVector ();
  y_temp_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/likelihood_function2/inputs/ y_temp");
 y_temp_stream<< y_temp;
std::cout <<"y_temp values: "<< y_temp << std::endl;
 y_temp_stream.close();
 NumericMatrix treetable_temp = RcppDeepState_NumericMatrix ();
  treetable_temp_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/likelihood_function2/inputs/ treetable_temp");
 treetable_temp_stream<< treetable_temp;
std::cout <<"treetable_temp values: "<< treetable_temp << std::endl;
 treetable_temp_stream.close();
 NumericMatrix obs_to_nodes_temp = RcppDeepState_NumericMatrix ();
  obs_to_nodes_temp_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/likelihood_function2/inputs/ obs_to_nodes_temp");
 obs_to_nodes_temp_stream<< obs_to_nodes_temp;
std::cout <<"obs_to_nodes_temp values: "<< obs_to_nodes_temp << std::endl;
 obs_to_nodes_temp_stream.close();
 double a = RcppDeepState_double ();
  a_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/likelihood_function2/inputs/ a");
 a_stream<< a;
std::cout <<"a values: "<< a << std::endl;
 a_stream.close();
 double mu = RcppDeepState_double ();
  mu_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/likelihood_function2/inputs/ mu");
 mu_stream<< mu;
std::cout <<"mu values: "<< mu << std::endl;
 mu_stream.close();
 double nu = RcppDeepState_double ();
  nu_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/likelihood_function2/inputs/ nu");
 nu_stream<< nu;
std::cout <<"nu values: "<< nu << std::endl;
 nu_stream.close();
 double lambda = RcppDeepState_double ();
  lambda_stream.open("/home/akhila/Documents/compileAttributescheck/bartBMA/inst/testfiles/likelihood_function2/inputs/ lambda");
 lambda_stream<< lambda;
std::cout <<"lambda values: "<< lambda << std::endl;
 lambda_stream.close();
 std::cout << "input ends" << std::endl;
 try{
likelihood_function2( y_temp, treetable_temp, obs_to_nodes_temp, a, mu, nu, lambda);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
