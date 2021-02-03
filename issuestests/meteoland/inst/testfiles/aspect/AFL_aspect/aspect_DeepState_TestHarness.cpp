#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

NumericVector aspect(NumericVector data, int nrows, int ncols, double cellWidth, double cellHeight);

TEST(meteoland_deepstate_test,aspect_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericVector data  = RcppDeepState_NumericVector();
  std::string data_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/aspect/AFL_aspect/afl_inputs/" + std::to_string(t) + "_data.qs";
  qs::c_qsave(data,data_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "data values: "<< data << std::endl;
  IntegerVector nrows(1);
  nrows[0]  = RcppDeepState_int();
  std::string nrows_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/aspect/AFL_aspect/afl_inputs/" + std::to_string(t) + "_nrows.qs";
  qs::c_qsave(nrows,nrows_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nrows values: "<< nrows << std::endl;
  IntegerVector ncols(1);
  ncols[0]  = RcppDeepState_int();
  std::string ncols_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/aspect/AFL_aspect/afl_inputs/" + std::to_string(t) + "_ncols.qs";
  qs::c_qsave(ncols,ncols_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "ncols values: "<< ncols << std::endl;
  NumericVector cellWidth(1);
  cellWidth[0]  = RcppDeepState_double();
  std::string cellWidth_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/aspect/AFL_aspect/afl_inputs/" + std::to_string(t) + "_cellWidth.qs";
  qs::c_qsave(cellWidth,cellWidth_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cellWidth values: "<< cellWidth << std::endl;
  NumericVector cellHeight(1);
  cellHeight[0]  = RcppDeepState_double();
  std::string cellHeight_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/meteoland/inst/testfiles/aspect/AFL_aspect/afl_inputs/" + std::to_string(t) + "_cellHeight.qs";
  qs::c_qsave(cellHeight,cellHeight_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "cellHeight values: "<< cellHeight << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    aspect(data,nrows[0],ncols[0],cellWidth[0],cellHeight[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
