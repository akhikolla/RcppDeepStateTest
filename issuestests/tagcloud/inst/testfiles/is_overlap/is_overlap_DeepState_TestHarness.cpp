#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

LogicalVector is_overlap(NumericVector box, NumericMatrix boxes);

TEST(tagcloud_deepstate_test,is_overlap_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector box  = RcppDeepState_NumericVector();
  qs::c_qsave(box,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/tagcloud/inst/testfiles/is_overlap/inputs/box.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "box values: "<< box << std::endl;
  NumericMatrix boxes  = RcppDeepState_NumericMatrix();
  qs::c_qsave(boxes,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/tagcloud/inst/testfiles/is_overlap/inputs/boxes.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "boxes values: "<< boxes << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    is_overlap(box,boxes);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
