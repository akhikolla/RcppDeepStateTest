#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix clean_moves_matrix(NumericVector theta, NumericMatrix moves, int n_zones);

TEST(SpatialEpi_deepstate_test,clean_moves_matrix_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector theta  = RcppDeepState_NumericVector();
  qs::c_qsave(theta,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/clean_moves_matrix/inputs/theta.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "theta values: "<< theta << std::endl;
  NumericMatrix moves  = RcppDeepState_NumericMatrix();
  qs::c_qsave(moves,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/clean_moves_matrix/inputs/moves.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "moves values: "<< moves << std::endl;
  IntegerVector n_zones(1);
  n_zones[0]  = RcppDeepState_int();
  qs::c_qsave(n_zones,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/SpatialEpi/inst/testfiles/clean_moves_matrix/inputs/n_zones.qs",
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
