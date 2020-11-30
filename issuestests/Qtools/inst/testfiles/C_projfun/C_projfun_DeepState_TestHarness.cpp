#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List C_projfun(NumericMatrix x, NumericMatrix z, NumericVector sgn, int nx, int nz, int p, int ndir);

TEST(Qtools_deepstate_test,C_projfun_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericMatrix z  = RcppDeepState_NumericMatrix();
  qs::c_qsave(z,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/inputs/z.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  NumericVector sgn  = RcppDeepState_NumericVector();
  qs::c_qsave(sgn,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/inputs/sgn.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sgn values: "<< sgn << std::endl;
  IntegerVector nx(1);
  nx[0]  = RcppDeepState_int();
  qs::c_qsave(nx,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/inputs/nx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nx values: "<< nx << std::endl;
  IntegerVector nz(1);
  nz[0]  = RcppDeepState_int();
  qs::c_qsave(nz,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/inputs/nz.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nz values: "<< nz << std::endl;
  IntegerVector p(1);
  p[0]  = RcppDeepState_int();
  qs::c_qsave(p,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/inputs/p.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "p values: "<< p << std::endl;
  IntegerVector ndir(1);
  ndir[0]  = RcppDeepState_int();
  qs::c_qsave(ndir,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_projfun/inputs/ndir.qs",
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
