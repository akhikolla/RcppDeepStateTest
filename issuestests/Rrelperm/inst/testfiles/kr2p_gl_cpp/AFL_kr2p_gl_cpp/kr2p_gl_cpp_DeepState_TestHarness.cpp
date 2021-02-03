#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix kr2p_gl_cpp(double SWCON, double SOIRG, double SORG, double SGCON, double SGCRIT, double KRGCL, double KROGCG, double NG, double NOG, int NP);

TEST(Rrelperm_deepstate_test,kr2p_gl_cpp_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector SWCON(1);
  SWCON[0]  = RcppDeepState_double();
  std::string SWCON_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_gl_cpp/AFL_kr2p_gl_cpp/afl_inputs/" + std::to_string(t) + "_SWCON.qs";
  qs::c_qsave(SWCON,SWCON_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SWCON values: "<< SWCON << std::endl;
  NumericVector SOIRG(1);
  SOIRG[0]  = RcppDeepState_double();
  std::string SOIRG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_gl_cpp/AFL_kr2p_gl_cpp/afl_inputs/" + std::to_string(t) + "_SOIRG.qs";
  qs::c_qsave(SOIRG,SOIRG_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SOIRG values: "<< SOIRG << std::endl;
  NumericVector SORG(1);
  SORG[0]  = RcppDeepState_double();
  std::string SORG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_gl_cpp/AFL_kr2p_gl_cpp/afl_inputs/" + std::to_string(t) + "_SORG.qs";
  qs::c_qsave(SORG,SORG_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SORG values: "<< SORG << std::endl;
  NumericVector SGCON(1);
  SGCON[0]  = RcppDeepState_double();
  std::string SGCON_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_gl_cpp/AFL_kr2p_gl_cpp/afl_inputs/" + std::to_string(t) + "_SGCON.qs";
  qs::c_qsave(SGCON,SGCON_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SGCON values: "<< SGCON << std::endl;
  NumericVector SGCRIT(1);
  SGCRIT[0]  = RcppDeepState_double();
  std::string SGCRIT_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_gl_cpp/AFL_kr2p_gl_cpp/afl_inputs/" + std::to_string(t) + "_SGCRIT.qs";
  qs::c_qsave(SGCRIT,SGCRIT_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "SGCRIT values: "<< SGCRIT << std::endl;
  NumericVector KRGCL(1);
  KRGCL[0]  = RcppDeepState_double();
  std::string KRGCL_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_gl_cpp/AFL_kr2p_gl_cpp/afl_inputs/" + std::to_string(t) + "_KRGCL.qs";
  qs::c_qsave(KRGCL,KRGCL_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "KRGCL values: "<< KRGCL << std::endl;
  NumericVector KROGCG(1);
  KROGCG[0]  = RcppDeepState_double();
  std::string KROGCG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_gl_cpp/AFL_kr2p_gl_cpp/afl_inputs/" + std::to_string(t) + "_KROGCG.qs";
  qs::c_qsave(KROGCG,KROGCG_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "KROGCG values: "<< KROGCG << std::endl;
  NumericVector NG(1);
  NG[0]  = RcppDeepState_double();
  std::string NG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_gl_cpp/AFL_kr2p_gl_cpp/afl_inputs/" + std::to_string(t) + "_NG.qs";
  qs::c_qsave(NG,NG_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NG values: "<< NG << std::endl;
  NumericVector NOG(1);
  NOG[0]  = RcppDeepState_double();
  std::string NOG_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_gl_cpp/AFL_kr2p_gl_cpp/afl_inputs/" + std::to_string(t) + "_NOG.qs";
  qs::c_qsave(NOG,NOG_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NOG values: "<< NOG << std::endl;
  IntegerVector NP(1);
  NP[0]  = RcppDeepState_int();
  std::string NP_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Rrelperm/inst/testfiles/kr2p_gl_cpp/AFL_kr2p_gl_cpp/afl_inputs/" + std::to_string(t) + "_NP.qs";
  qs::c_qsave(NP,NP_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "NP values: "<< NP << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    kr2p_gl_cpp(SWCON[0],SOIRG[0],SORG[0],SGCON[0],SGCRIT[0],KRGCL[0],KROGCG[0],NG[0],NOG[0],NP[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
