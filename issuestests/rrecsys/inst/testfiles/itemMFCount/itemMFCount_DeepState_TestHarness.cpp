#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector itemMFCount(NumericMatrix sim_index, NumericVector user_vector, double pt);

TEST(rrecsys_deepstate_test,itemMFCount_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix sim_index  = RcppDeepState_NumericMatrix();
  qs::c_qsave(sim_index,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/itemMFCount/inputs/sim_index.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sim_index values: "<< sim_index << std::endl;
  NumericVector user_vector  = RcppDeepState_NumericVector();
  qs::c_qsave(user_vector,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/itemMFCount/inputs/user_vector.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "user_vector values: "<< user_vector << std::endl;
  NumericVector pt(1);
  pt[0]  = RcppDeepState_double();
  qs::c_qsave(pt,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/itemMFCount/inputs/pt.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "pt values: "<< pt << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    itemMFCount(sim_index,user_vector,pt[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
