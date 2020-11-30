#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

Rcpp::IntegerVector clipVec(IntegerVector id, IntegerVector seq, IntegerVector event);

TEST(simstudy_deepstate_test,clipVec_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector id  = RcppDeepState_IntegerVector();
  qs::c_qsave(id,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/clipVec/inputs/id.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "id values: "<< id << std::endl;
  IntegerVector seq  = RcppDeepState_IntegerVector();
  qs::c_qsave(seq,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/clipVec/inputs/seq.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "seq values: "<< seq << std::endl;
  IntegerVector event  = RcppDeepState_IntegerVector();
  qs::c_qsave(event,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/simstudy/inst/testfiles/clipVec/inputs/event.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "event values: "<< event << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    clipVec(id,seq,event);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
