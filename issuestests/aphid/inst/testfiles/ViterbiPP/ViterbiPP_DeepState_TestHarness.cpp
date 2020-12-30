#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List ViterbiPP(NumericMatrix Ax, NumericMatrix Ay, NumericMatrix Ex, NumericMatrix Ey, NumericVector qe, int type, IntegerVector windowspace, double offset);

TEST(aphid_deepstate_test,ViterbiPP_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix Ax  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Ax,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/inputs/Ax.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Ax values: "<< Ax << std::endl;
  NumericMatrix Ay  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Ay,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/inputs/Ay.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Ay values: "<< Ay << std::endl;
  NumericMatrix Ex  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Ex,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/inputs/Ex.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Ex values: "<< Ex << std::endl;
  NumericMatrix Ey  = RcppDeepState_NumericMatrix();
  qs::c_qsave(Ey,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/inputs/Ey.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Ey values: "<< Ey << std::endl;
  NumericVector qe  = RcppDeepState_NumericVector();
  qs::c_qsave(qe,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/inputs/qe.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "qe values: "<< qe << std::endl;
  IntegerVector type(1);
  type[0]  = RcppDeepState_int();
  qs::c_qsave(type,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/inputs/type.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "type values: "<< type << std::endl;
  IntegerVector windowspace  = RcppDeepState_IntegerVector();
  qs::c_qsave(windowspace,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/inputs/windowspace.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "windowspace values: "<< windowspace << std::endl;
  NumericVector offset(1);
  offset[0]  = RcppDeepState_double();
  qs::c_qsave(offset,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/inputs/offset.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "offset values: "<< offset << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    ViterbiPP(Ax,Ay,Ex,Ey,qe,type[0],windowspace,offset[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
