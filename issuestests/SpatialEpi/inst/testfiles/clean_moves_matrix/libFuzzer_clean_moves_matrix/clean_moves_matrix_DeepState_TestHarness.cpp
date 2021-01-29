#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix clean_moves_matrix(NumericVector theta, NumericMatrix moves, int n_zones);

TEST(SpatialEpi_deepstate_test,clean_moves_matrix_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector theta  = RcppDeepState_NumericVector();
  std::string theta_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/clean_moves_matrix/libFuzzer_clean_moves_matrix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_theta.qs";
  qs::c_qsave(theta,theta_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  NumericMatrix moves  = RcppDeepState_NumericMatrix();
  std::string moves_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/clean_moves_matrix/libFuzzer_clean_moves_matrix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_moves.qs";
  qs::c_qsave(moves,moves_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "moves values: "<< moves << std::endl;
  IntegerVector n_zones(1);
  n_zones[0]  = RcppDeepState_int();
  std::string n_zones_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/clean_moves_matrix/libFuzzer_clean_moves_matrix/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_n_zones.qs";
  qs::c_qsave(n_zones,n_zones_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_zones values: "<< n_zones << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    clean_moves_matrix(theta,moves,n_zones[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
