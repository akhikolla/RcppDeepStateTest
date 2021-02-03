#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List ViterbiPP(NumericMatrix Ax, NumericMatrix Ay, NumericMatrix Ex, NumericMatrix Ey, NumericVector qe, int type, IntegerVector windowspace, double offset);

TEST(aphid_deepstate_test,ViterbiPP_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix Ax  = RcppDeepState_NumericMatrix();
  std::string Ax_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/AFL_ViterbiPP/afl_inputs/" + std::to_string(t) + "_Ax.qs";
  qs::c_qsave(Ax,Ax_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Ax values: "<< Ax << std::endl;
  NumericMatrix Ay  = RcppDeepState_NumericMatrix();
  std::string Ay_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/AFL_ViterbiPP/afl_inputs/" + std::to_string(t) + "_Ay.qs";
  qs::c_qsave(Ay,Ay_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Ay values: "<< Ay << std::endl;
  NumericMatrix Ex  = RcppDeepState_NumericMatrix();
  std::string Ex_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/AFL_ViterbiPP/afl_inputs/" + std::to_string(t) + "_Ex.qs";
  qs::c_qsave(Ex,Ex_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Ex values: "<< Ex << std::endl;
  NumericMatrix Ey  = RcppDeepState_NumericMatrix();
  std::string Ey_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/AFL_ViterbiPP/afl_inputs/" + std::to_string(t) + "_Ey.qs";
  qs::c_qsave(Ey,Ey_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "Ey values: "<< Ey << std::endl;
  NumericVector qe  = RcppDeepState_NumericVector();
  std::string qe_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/AFL_ViterbiPP/afl_inputs/" + std::to_string(t) + "_qe.qs";
  qs::c_qsave(qe,qe_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "qe values: "<< qe << std::endl;
  IntegerVector type(1);
  type[0]  = RcppDeepState_int();
  std::string type_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/AFL_ViterbiPP/afl_inputs/" + std::to_string(t) + "_type.qs";
  qs::c_qsave(type,type_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "type values: "<< type << std::endl;
  IntegerVector windowspace  = RcppDeepState_IntegerVector();
  std::string windowspace_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/AFL_ViterbiPP/afl_inputs/" + std::to_string(t) + "_windowspace.qs";
  qs::c_qsave(windowspace,windowspace_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "windowspace values: "<< windowspace << std::endl;
  NumericVector offset(1);
  offset[0]  = RcppDeepState_double();
  std::string offset_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/aphid/inst/testfiles/ViterbiPP/AFL_ViterbiPP/afl_inputs/" + std::to_string(t) + "_offset.qs";
  qs::c_qsave(offset,offset_t,
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
