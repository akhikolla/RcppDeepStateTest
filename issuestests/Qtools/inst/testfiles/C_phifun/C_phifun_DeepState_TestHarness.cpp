#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List C_phifun(NumericMatrix x, NumericMatrix z, int nx, int nz, int B, int ndir, int ng, NumericVector taus, IntegerVector minn, IntegerVector maxn);

TEST(Qtools_deepstate_test,C_phifun_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  qs::c_qsave(x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/inputs/x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericMatrix z  = RcppDeepState_NumericMatrix();
  qs::c_qsave(z,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/inputs/z.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  IntegerVector nx(1);
  nx[0]  = RcppDeepState_int();
  qs::c_qsave(nx,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/inputs/nx.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nx values: "<< nx << std::endl;
  IntegerVector nz(1);
  nz[0]  = RcppDeepState_int();
  qs::c_qsave(nz,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/inputs/nz.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nz values: "<< nz << std::endl;
  IntegerVector B(1);
  B[0]  = RcppDeepState_int();
  qs::c_qsave(B,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/inputs/B.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B values: "<< B << std::endl;
  IntegerVector ndir(1);
  ndir[0]  = RcppDeepState_int();
  qs::c_qsave(ndir,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/inputs/ndir.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ndir values: "<< ndir << std::endl;
  IntegerVector ng(1);
  ng[0]  = RcppDeepState_int();
  qs::c_qsave(ng,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/inputs/ng.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ng values: "<< ng << std::endl;
  NumericVector taus  = RcppDeepState_NumericVector();
  qs::c_qsave(taus,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/inputs/taus.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "taus values: "<< taus << std::endl;
  IntegerVector minn  = RcppDeepState_IntegerVector();
  qs::c_qsave(minn,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/inputs/minn.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "minn values: "<< minn << std::endl;
  IntegerVector maxn  = RcppDeepState_IntegerVector();
  qs::c_qsave(maxn,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/inputs/maxn.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "maxn values: "<< maxn << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    C_phifun(x,z,nx[0],nz[0],B[0],ndir[0],ng[0],taus,minn,maxn);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
