#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericMatrix dispersal_kernel_cpp(int cur_x, int cur_y, int nc, int nr, NumericMatrix dk, NumericVector coefs, int standardize, IntegerVector first_order_terms, IntegerVector second_order_terms, NumericMatrix hab, NumericMatrix other_covars, IntegerVector other_covars_indicator, int stop);

TEST(amt_deepstate_test,dispersal_kernel_cpp_test){
  static int rinside_flag = 0;
  if(rinside_flag == 0)
  {
    rinside_flag = 1;
    RInside R;
  } std::time_t current_timestamp = std::time(0);
  std::cout << "input starts" << std::endl;
  IntegerVector cur_x(1);
  cur_x[0]  = RcppDeepState_int();
  std::string cur_x_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cur_x.qs";
  qs::c_qsave(cur_x,cur_x_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cur_x values: "<< cur_x << std::endl;
  IntegerVector cur_y(1);
  cur_y[0]  = RcppDeepState_int();
  std::string cur_y_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_cur_y.qs";
  qs::c_qsave(cur_y,cur_y_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cur_y values: "<< cur_y << std::endl;
  IntegerVector nc(1);
  nc[0]  = RcppDeepState_int();
  std::string nc_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nc.qs";
  qs::c_qsave(nc,nc_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nc values: "<< nc << std::endl;
  IntegerVector nr(1);
  nr[0]  = RcppDeepState_int();
  std::string nr_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_nr.qs";
  qs::c_qsave(nr,nr_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nr values: "<< nr << std::endl;
  NumericMatrix dk  = RcppDeepState_NumericMatrix();
  std::string dk_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_dk.qs";
  qs::c_qsave(dk,dk_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "dk values: "<< dk << std::endl;
  NumericVector coefs  = RcppDeepState_NumericVector();
  std::string coefs_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_coefs.qs";
  qs::c_qsave(coefs,coefs_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "coefs values: "<< coefs << std::endl;
  IntegerVector standardize(1);
  standardize[0]  = RcppDeepState_int();
  std::string standardize_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_standardize.qs";
  qs::c_qsave(standardize,standardize_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "standardize values: "<< standardize << std::endl;
  IntegerVector first_order_terms  = RcppDeepState_IntegerVector();
  std::string first_order_terms_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_first_order_terms.qs";
  qs::c_qsave(first_order_terms,first_order_terms_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "first_order_terms values: "<< first_order_terms << std::endl;
  IntegerVector second_order_terms  = RcppDeepState_IntegerVector();
  std::string second_order_terms_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_second_order_terms.qs";
  qs::c_qsave(second_order_terms,second_order_terms_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "second_order_terms values: "<< second_order_terms << std::endl;
  NumericMatrix hab  = RcppDeepState_NumericMatrix();
  std::string hab_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_hab.qs";
  qs::c_qsave(hab,hab_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "hab values: "<< hab << std::endl;
  NumericMatrix other_covars  = RcppDeepState_NumericMatrix();
  std::string other_covars_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_other_covars.qs";
  qs::c_qsave(other_covars,other_covars_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "other_covars values: "<< other_covars << std::endl;
  IntegerVector other_covars_indicator  = RcppDeepState_IntegerVector();
  std::string other_covars_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_other_covars.qs";
  std::string other_covars_indicator_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_other_covars_indicator.qs";
  qs::c_qsave(other_covars_indicator,other_covars_indicator_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "other_covars_indicator values: "<< other_covars_indicator << std::endl;
  IntegerVector stop(1);
  stop[0]  = RcppDeepState_int();
  std::string stop_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/amt/inst/testfiles/dispersal_kernel_cpp/libFuzzer_dispersal_kernel_cpp/libfuzzer_inputs/" + std::to_string(current_timestamp) +
          "_stop.qs";
  qs::c_qsave(stop,stop_t,
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
