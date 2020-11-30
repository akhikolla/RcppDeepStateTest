#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List func_dc_by(NumericMatrix z, double dmby, double dtby);

TEST(factorcpt_deepstate_test,func_dc_by_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix z  = RcppDeepState_NumericMatrix();
  qs::c_qsave(z,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/factorcpt/inst/testfiles/func_dc_by/inputs/z.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector dmby(1);
  dmby[0]  = RcppDeepState_double();
  qs::c_qsave(dmby,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/factorcpt/inst/testfiles/func_dc_by/inputs/dmby.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dmby values: "<< dmby << std::endl;
  NumericVector dtby(1);
  dtby[0]  = RcppDeepState_double();
  qs::c_qsave(dtby,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/factorcpt/inst/testfiles/func_dc_by/inputs/dtby.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dtby values: "<< dtby << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    func_dc_by(z,dmby[0],dtby[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
