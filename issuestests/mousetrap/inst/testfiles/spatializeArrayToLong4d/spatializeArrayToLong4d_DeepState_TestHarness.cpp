#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix spatializeArrayToLong4d(NumericMatrix xs, NumericMatrix ys, NumericMatrix z1s, NumericMatrix z2s, NumericVector n_pts);

TEST(mousetrap_deepstate_test,spatializeArrayToLong4d_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix xs  = RcppDeepState_NumericMatrix();
  qs::c_qsave(xs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatializeArrayToLong4d/inputs/xs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "xs values: "<< xs << std::endl;
  NumericMatrix ys  = RcppDeepState_NumericMatrix();
  qs::c_qsave(ys,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatializeArrayToLong4d/inputs/ys.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ys values: "<< ys << std::endl;
  NumericMatrix z1s  = RcppDeepState_NumericMatrix();
  qs::c_qsave(z1s,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatializeArrayToLong4d/inputs/z1s.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z1s values: "<< z1s << std::endl;
  NumericMatrix z2s  = RcppDeepState_NumericMatrix();
  qs::c_qsave(z2s,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatializeArrayToLong4d/inputs/z2s.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z2s values: "<< z2s << std::endl;
  NumericVector n_pts  = RcppDeepState_NumericVector();
  qs::c_qsave(n_pts,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/mousetrap/inst/testfiles/spatializeArrayToLong4d/inputs/n_pts.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n_pts values: "<< n_pts << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    spatializeArrayToLong4d(xs,ys,z1s,z2s,n_pts);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
