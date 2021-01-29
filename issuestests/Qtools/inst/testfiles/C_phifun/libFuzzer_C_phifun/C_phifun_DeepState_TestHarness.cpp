#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List C_phifun(NumericMatrix x, NumericMatrix z, int nx, int nz, int B, int ndir, int ng, NumericVector taus, IntegerVector minn, IntegerVector maxn);

TEST(Qtools_deepstate_test,C_phifun_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix x  = RcppDeepState_NumericMatrix();
  std::string x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/libFuzzer_C_phifun/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_x.qs";
  qs::c_qsave(x,x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "x values: "<< x << std::endl;
  NumericMatrix z  = RcppDeepState_NumericMatrix();
  std::string z_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/libFuzzer_C_phifun/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_z.qs";
  qs::c_qsave(z,z_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "z values: "<< z << std::endl;
  IntegerVector nx(1);
  nx[0]  = RcppDeepState_int();
  std::string nx_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/libFuzzer_C_phifun/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nx.qs";
  qs::c_qsave(nx,nx_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nx values: "<< nx << std::endl;
  IntegerVector nz(1);
  nz[0]  = RcppDeepState_int();
  std::string nz_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/libFuzzer_C_phifun/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nz.qs";
  qs::c_qsave(nz,nz_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nz values: "<< nz << std::endl;
  IntegerVector B(1);
  B[0]  = RcppDeepState_int();
  std::string B_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/libFuzzer_C_phifun/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_B.qs";
  qs::c_qsave(B,B_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "B values: "<< B << std::endl;
  IntegerVector ndir(1);
  ndir[0]  = RcppDeepState_int();
  std::string ndir_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/libFuzzer_C_phifun/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ndir.qs";
  qs::c_qsave(ndir,ndir_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ndir values: "<< ndir << std::endl;
  IntegerVector ng(1);
  ng[0]  = RcppDeepState_int();
  std::string ng_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/libFuzzer_C_phifun/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_ng.qs";
  qs::c_qsave(ng,ng_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ng values: "<< ng << std::endl;
  NumericVector taus  = RcppDeepState_NumericVector();
  std::string taus_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/libFuzzer_C_phifun/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_taus.qs";
  qs::c_qsave(taus,taus_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "taus values: "<< taus << std::endl;
  IntegerVector minn  = RcppDeepState_IntegerVector();
  std::string minn_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/libFuzzer_C_phifun/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_minn.qs";
  qs::c_qsave(minn,minn_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "minn values: "<< minn << std::endl;
  IntegerVector maxn  = RcppDeepState_IntegerVector();
  std::string maxn_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/Qtools/inst/testfiles/C_phifun/libFuzzer_C_phifun/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_maxn.qs";
  qs::c_qsave(maxn,maxn_t,
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
