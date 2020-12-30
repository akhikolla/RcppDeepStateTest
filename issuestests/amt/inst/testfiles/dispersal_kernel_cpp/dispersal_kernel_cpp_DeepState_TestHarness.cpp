#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix dispersal_kernel_cpp(int cur_x, int cur_y, int nc, int nr, NumericMatrix dk, NumericVector coefs, int standardize, IntegerVector first_order_terms, IntegerVector second_order_terms, NumericMatrix hab, NumericMatrix other_covars, IntegerVector other_covars_indicator, int stop);

TEST(amt_deepstate_test,dispersal_kernel_cpp_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector cur_x(1);
  cur_x[0]  = RcppDeepState_int();
  qs::c_qsave(cur_x,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/inputs/cur_x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cur_x values: "<< cur_x << std::endl;
  IntegerVector cur_y(1);
  cur_y[0]  = RcppDeepState_int();
  qs::c_qsave(cur_y,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/inputs/cur_y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cur_y values: "<< cur_y << std::endl;
  IntegerVector nc(1);
  nc[0]  = RcppDeepState_int();
  qs::c_qsave(nc,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/inputs/nc.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nc values: "<< nc << std::endl;
  IntegerVector nr(1);
  nr[0]  = RcppDeepState_int();
  qs::c_qsave(nr,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/inputs/nr.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nr values: "<< nr << std::endl;
  NumericMatrix dk  = RcppDeepState_NumericMatrix();
  qs::c_qsave(dk,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/inputs/dk.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dk values: "<< dk << std::endl;
  NumericVector coefs  = RcppDeepState_NumericVector();
  qs::c_qsave(coefs,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/inputs/coefs.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "coefs values: "<< coefs << std::endl;
  IntegerVector standardize(1);
  standardize[0]  = RcppDeepState_int();
  qs::c_qsave(standardize,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/inputs/standardize.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "standardize values: "<< standardize << std::endl;
  IntegerVector first_order_terms  = RcppDeepState_IntegerVector();
  qs::c_qsave(first_order_terms,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/inputs/first_order_terms.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "first_order_terms values: "<< first_order_terms << std::endl;
  IntegerVector second_order_terms  = RcppDeepState_IntegerVector();
  qs::c_qsave(second_order_terms,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/inputs/second_order_terms.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "second_order_terms values: "<< second_order_terms << std::endl;
  NumericMatrix hab  = RcppDeepState_NumericMatrix();
  qs::c_qsave(hab,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/inputs/hab.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "hab values: "<< hab << std::endl;
  NumericMatrix other_covars  = RcppDeepState_NumericMatrix();
  qs::c_qsave(other_covars,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/inputs/other_covars.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "other_covars values: "<< other_covars << std::endl;
  IntegerVector other_covars_indicator  = RcppDeepState_IntegerVector();
  qs::c_qsave(other_covars_indicator,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/inputs/other_covars_indicator.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "other_covars_indicator values: "<< other_covars_indicator << std::endl;
  IntegerVector stop(1);
  stop[0]  = RcppDeepState_int();
  qs::c_qsave(stop,"/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/inputs/stop.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "stop values: "<< stop << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    dispersal_kernel_cpp(cur_x[0],cur_y[0],nc[0],nr[0],dk,coefs,standardize[0],first_order_terms,second_order_terms,hab,other_covars,other_covars_indicator,stop[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
