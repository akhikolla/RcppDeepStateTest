#include <DeepState.hpp>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <fstream>
 double rtn1(const double mean, const double sd, const double low, const double high);
TEST(BNPMIXcluster_deepstate_test,rtn1_test){
std::ofstream  mean_stream;
std::ofstream  sd_stream;
std::ofstream  low_stream;
std::ofstream  high_stream;
RInside();
std::cout << "input starts" << std::endl;
  double mean = RcppDeepState_double ();
  mean_stream.open("/home/akhila/Documents/compileAttributescheck/BNPMIXcluster/inst/testfiles/rtn1/inputs/ mean");
 mean_stream<< mean;
std::cout <<"mean values: "<< mean << std::endl;
 mean_stream.close();
  double sd = RcppDeepState_double ();
  sd_stream.open("/home/akhila/Documents/compileAttributescheck/BNPMIXcluster/inst/testfiles/rtn1/inputs/ sd");
 sd_stream<< sd;
std::cout <<"sd values: "<< sd << std::endl;
 sd_stream.close();
  double low = RcppDeepState_double ();
  low_stream.open("/home/akhila/Documents/compileAttributescheck/BNPMIXcluster/inst/testfiles/rtn1/inputs/ low");
 low_stream<< low;
std::cout <<"low values: "<< low << std::endl;
 low_stream.close();
  double high = RcppDeepState_double ();
  high_stream.open("/home/akhila/Documents/compileAttributescheck/BNPMIXcluster/inst/testfiles/rtn1/inputs/ high");
 high_stream<< high;
std::cout <<"high values: "<< high << std::endl;
 high_stream.close();
 std::cout << "input ends" << std::endl;
 try{
rtn1( mean, sd, low, high);
}
catch(Rcpp::exception& e){
std::cout<<"Exception Handled"<<std::endl;
} 
 }
