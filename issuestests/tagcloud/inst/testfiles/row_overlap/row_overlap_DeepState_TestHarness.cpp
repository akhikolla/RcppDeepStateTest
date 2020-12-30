#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

LogicalVector row_overlap(NumericVector row_in, NumericMatrix boxes);

TEST(tagcloud_deepstate_test,row_overlap_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector row_in  = RcppDeepState_NumericVector();
  qs::c_qsave(row_in,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/tagcloud/inst/testfiles/row_overlap/inputs/row_in.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "row_in values: "<< row_in << std::endl;
  NumericMatrix boxes  = RcppDeepState_NumericMatrix();
  qs::c_qsave(boxes,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/tagcloud/inst/testfiles/row_overlap/inputs/boxes.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "boxes values: "<< boxes << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    row_overlap(row_in,boxes);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
