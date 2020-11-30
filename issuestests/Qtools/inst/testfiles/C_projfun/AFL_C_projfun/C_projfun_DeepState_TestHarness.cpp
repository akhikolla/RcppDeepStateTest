#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List C_projfun(NumericMatrix x, NumericMatrix z, NumericVector sgn, int nx, int nz, int p, int ndir);

TEST(Qtools_deepstate_test,C_projfun_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/AFL_C_projfun/afl_inputs/" + std::to_string(t) + "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericMatrix z  = RcppDeepState_NumericMatrix();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/AFL_C_projfun/afl_inputs/" + std::to_string(t) + "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector sgn  = RcppDeepState_NumericVector();
  std::string sgn_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/AFL_C_projfun/afl_inputs/" + std::to_string(t) + "_sgn.qs";
  qs::c_qsave(sgn,sgn_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sgn values: "<< sgn << std::endl;
  IntegerVector nx(1);
  nx[0]  = RcppDeepState_int();
  std::string nx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/AFL_C_projfun/afl_inputs/" + std::to_string(t) + "_nx.qs";
  qs::c_qsave(nx,nx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nx values: "<< nx << std::endl;
  IntegerVector nz(1);
  nz[0]  = RcppDeepState_int();
  std::string nz_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/AFL_C_projfun/afl_inputs/" + std::to_string(t) + "_nz.qs";
  qs::c_qsave(nz,nz_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nz values: "<< nz << std::endl;
  IntegerVector p(1);
  p[0]  = RcppDeepState_int();
  std::string p_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/AFL_C_projfun/afl_inputs/" + std::to_string(t) + "_p.qs";
  qs::c_qsave(p,p_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  IntegerVector ndir(1);
  ndir[0]  = RcppDeepState_int();
  std::string ndir_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/AFL_C_projfun/afl_inputs/" + std::to_string(t) + "_ndir.qs";
  qs::c_qsave(ndir,ndir_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ndir values: "<< ndir << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    C_projfun(x,z,sgn,nx[0],nz[0],p[0],ndir[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
