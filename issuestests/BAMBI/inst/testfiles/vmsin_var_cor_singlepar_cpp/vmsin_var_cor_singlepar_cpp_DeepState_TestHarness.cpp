#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List vmsin_var_cor_singlepar_cpp(double k1, double k2, double k3, arma::mat uni_rand, int ncores);

TEST(BAMBI_deepstate_test,vmsin_var_cor_singlepar_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  NumericVector k1(1);
  k1[0]  = RcppDeepState_double();
  qs::c_qsave(k1,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/vmsin_var_cor_singlepar_cpp/inputs/k1.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k1 values: "<< k1 << std::endl;
  NumericVector k2(1);
  k2[0]  = RcppDeepState_double();
  qs::c_qsave(k2,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/vmsin_var_cor_singlepar_cpp/inputs/k2.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k2 values: "<< k2 << std::endl;
  NumericVector k3(1);
  k3[0]  = RcppDeepState_double();
  qs::c_qsave(k3,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/vmsin_var_cor_singlepar_cpp/inputs/k3.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "k3 values: "<< k3 << std::endl;
  std::ofstream uni_rand_stream;
  arma::mat uni_rand  = RcppDeepState_mat();
  uni_rand_stream.open("/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/vmsin_var_cor_singlepar_cpp/inputs/uni_rand");
  uni_rand_stream << uni_rand;
  std::cout << "uni_rand values: "<< uni_rand << std::endl;
  uni_rand_stream.close();
  IntegerVector ncores(1);
  ncores[0]  = RcppDeepState_int();
  qs::c_qsave(ncores,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/BAMBI/inst/testfiles/vmsin_var_cor_singlepar_cpp/inputs/ncores.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ncores values: "<< ncores << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    vmsin_var_cor_singlepar_cpp(k1[0],k2[0],k3[0],uni_rand,ncores[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
