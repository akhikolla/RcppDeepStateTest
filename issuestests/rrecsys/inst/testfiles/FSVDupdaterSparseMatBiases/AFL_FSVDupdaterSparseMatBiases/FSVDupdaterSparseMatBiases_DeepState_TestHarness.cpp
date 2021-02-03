#include <fstream>
#include <ctime>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

List FSVDupdaterSparseMatBiases(NumericMatrix sparseRatingMat, double learningRate, double regCoef, int nrfeat, int steps, int nr_users, int nr_items, double globalbaseline);

TEST(rrecsys_deepstate_test,FSVDupdaterSparseMatBiases_test){
  RInside R;
  std::time_t t = std::time(0);
  std::cout << "input starts" << std::endl;
  NumericMatrix sparseRatingMat  = RcppDeepState_NumericMatrix();
  std::string sparseRatingMat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/AFL_FSVDupdaterSparseMatBiases/afl_inputs/" + std::to_string(t) + "_sparseRatingMat.qs";
  qs::c_qsave(sparseRatingMat,sparseRatingMat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "sparseRatingMat values: "<< sparseRatingMat << std::endl;
  NumericVector learningRate(1);
  learningRate[0]  = RcppDeepState_double();
  std::string learningRate_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/AFL_FSVDupdaterSparseMatBiases/afl_inputs/" + std::to_string(t) + "_learningRate.qs";
  qs::c_qsave(learningRate,learningRate_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "learningRate values: "<< learningRate << std::endl;
  NumericVector regCoef(1);
  regCoef[0]  = RcppDeepState_double();
  std::string regCoef_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/AFL_FSVDupdaterSparseMatBiases/afl_inputs/" + std::to_string(t) + "_regCoef.qs";
  qs::c_qsave(regCoef,regCoef_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "regCoef values: "<< regCoef << std::endl;
  IntegerVector nrfeat(1);
  nrfeat[0]  = RcppDeepState_int();
  std::string nrfeat_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/AFL_FSVDupdaterSparseMatBiases/afl_inputs/" + std::to_string(t) + "_nrfeat.qs";
  qs::c_qsave(nrfeat,nrfeat_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nrfeat values: "<< nrfeat << std::endl;
  IntegerVector steps(1);
  steps[0]  = RcppDeepState_int();
  std::string steps_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/AFL_FSVDupdaterSparseMatBiases/afl_inputs/" + std::to_string(t) + "_steps.qs";
  qs::c_qsave(steps,steps_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "steps values: "<< steps << std::endl;
  IntegerVector nr_users(1);
  nr_users[0]  = RcppDeepState_int();
  std::string nr_users_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/AFL_FSVDupdaterSparseMatBiases/afl_inputs/" + std::to_string(t) + "_nr_users.qs";
  qs::c_qsave(nr_users,nr_users_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nr_users values: "<< nr_users << std::endl;
  IntegerVector nr_items(1);
  nr_items[0]  = RcppDeepState_int();
  std::string nr_items_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/AFL_FSVDupdaterSparseMatBiases/afl_inputs/" + std::to_string(t) + "_nr_items.qs";
  qs::c_qsave(nr_items,nr_items_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "nr_items values: "<< nr_items << std::endl;
  NumericVector globalbaseline(1);
  globalbaseline[0]  = RcppDeepState_double();
  std::string globalbaseline_t = "/home/akhila/R/x86_64-pc-linux-gnu-library/3.6/RcppDeepState/extdata/issuestests/rrecsys/inst/testfiles/FSVDupdaterSparseMatBiases/AFL_FSVDupdaterSparseMatBiases/afl_inputs/" + std::to_string(t) + "_globalbaseline.qs";
  qs::c_qsave(globalbaseline,globalbaseline_t,
		"high", "zstd", 1, 15, true, 1);
  std::cout << "globalbaseline values: "<< globalbaseline << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    FSVDupdaterSparseMatBiases(sparseRatingMat,learningRate[0],regCoef[0],nrfeat[0],steps[0],nr_users[0],nr_items[0],globalbaseline[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
