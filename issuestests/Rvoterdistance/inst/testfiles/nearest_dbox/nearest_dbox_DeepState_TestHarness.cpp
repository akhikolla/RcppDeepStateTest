#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector nearest_dbox(NumericVector lat1d_vec, NumericVector lon1d_vec, NumericVector lat2d_vec, NumericVector lon2d_vec);

TEST(Rvoterdistance_deepstate_test,nearest_dbox_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector lat1d_vec  = RcppDeepState_NumericVector();
  qs::c_qsave(lat1d_vec,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/nearest_dbox/inputs/lat1d_vec.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat1d_vec values: "<< lat1d_vec << std::endl;
  NumericVector lon1d_vec  = RcppDeepState_NumericVector();
  qs::c_qsave(lon1d_vec,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/nearest_dbox/inputs/lon1d_vec.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon1d_vec values: "<< lon1d_vec << std::endl;
  NumericVector lat2d_vec  = RcppDeepState_NumericVector();
  qs::c_qsave(lat2d_vec,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/nearest_dbox/inputs/lat2d_vec.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lat2d_vec values: "<< lat2d_vec << std::endl;
  NumericVector lon2d_vec  = RcppDeepState_NumericVector();
  qs::c_qsave(lon2d_vec,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rvoterdistance/inst/testfiles/nearest_dbox/inputs/lon2d_vec.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "lon2d_vec values: "<< lon2d_vec << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    nearest_dbox(lat1d_vec,lon1d_vec,lat2d_vec,lon2d_vec);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
