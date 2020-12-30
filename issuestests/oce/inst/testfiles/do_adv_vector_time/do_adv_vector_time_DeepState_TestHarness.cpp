#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector do_adv_vector_time(NumericVector vvdStart, NumericVector vsdStart, NumericVector vsdTime, NumericVector vvdhStart, NumericVector vvdhTime, NumericVector n, NumericVector f);

TEST(oce_deepstate_test,do_adv_vector_time_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector vvdStart  = RcppDeepState_NumericVector();
  qs::c_qsave(vvdStart,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/inputs/vvdStart.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vvdStart values: "<< vvdStart << std::endl;
  NumericVector vsdStart  = RcppDeepState_NumericVector();
  qs::c_qsave(vsdStart,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/inputs/vsdStart.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vsdStart values: "<< vsdStart << std::endl;
  NumericVector vsdTime  = RcppDeepState_NumericVector();
  qs::c_qsave(vsdTime,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/inputs/vsdTime.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vsdTime values: "<< vsdTime << std::endl;
  NumericVector vvdhStart  = RcppDeepState_NumericVector();
  qs::c_qsave(vvdhStart,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/inputs/vvdhStart.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vvdhStart values: "<< vvdhStart << std::endl;
  NumericVector vvdhTime  = RcppDeepState_NumericVector();
  qs::c_qsave(vvdhTime,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/inputs/vvdhTime.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "vvdhTime values: "<< vvdhTime << std::endl;
  NumericVector n  = RcppDeepState_NumericVector();
  qs::c_qsave(n,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/inputs/n.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "n values: "<< n << std::endl;
  NumericVector f  = RcppDeepState_NumericVector();
  qs::c_qsave(f,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/oce/inst/testfiles/do_adv_vector_time/inputs/f.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "f values: "<< f << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    do_adv_vector_time(vvdStart,vsdStart,vsdTime,vvdhStart,vvdhTime,n,f);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
