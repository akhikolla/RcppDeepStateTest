#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List ViterbiD(IntegerVector x, IntegerVector y, int type, double d, double e, NumericMatrix S, IntegerVector windowspace, double offset);

TEST(aphid_deepstate_test,ViterbiD_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector x  = RcppDeepState_IntegerVector();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  IntegerVector y  = RcppDeepState_IntegerVector();
  qs::c_qsave(y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/inputs/y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "y values: "<< y << std::endl;
  IntegerVector type(1);
  type[0]  = RcppDeepState_int();
  qs::c_qsave(type,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/inputs/type.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "type values: "<< type << std::endl;
  NumericVector d(1);
  d[0]  = RcppDeepState_double();
  qs::c_qsave(d,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/inputs/d.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "d values: "<< d << std::endl;
  NumericVector e(1);
  e[0]  = RcppDeepState_double();
  qs::c_qsave(e,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/inputs/e.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "e values: "<< e << std::endl;
  NumericMatrix S  = RcppDeepState_NumericMatrix();
  qs::c_qsave(S,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/inputs/S.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "S values: "<< S << std::endl;
  IntegerVector windowspace  = RcppDeepState_IntegerVector();
  qs::c_qsave(windowspace,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/inputs/windowspace.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "windowspace values: "<< windowspace << std::endl;
  NumericVector offset(1);
  offset[0]  = RcppDeepState_double();
  qs::c_qsave(offset,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiD/inputs/offset.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "offset values: "<< offset << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ViterbiD(x,y,type[0],d[0],e[0],S,windowspace,offset[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
