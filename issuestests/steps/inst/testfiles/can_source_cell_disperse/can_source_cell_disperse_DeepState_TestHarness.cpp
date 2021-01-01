// AUTOMATICALLY GENERATED BY RCPPDEEPSTATE PLEASE DO NOT EDIT BY HAND, INSTEAD EDIT
// can_source_cell_disperse_DeepState_TestHarness_generation.cpp and can_source_cell_disperse_DeepState_TestHarness_checks.cpp

#include <fstream>
#include <RInside.h>
#include <iostream>
#include <RcppDeepState.h>
#include <qs.h>
#include <DeepState.hpp>

IntegerVector can_source_cell_disperse(int source_y, int source_x, NumericMatrix iterative_population_state, NumericMatrix future_population_state, NumericMatrix carrying_capacity_available, NumericMatrix permeability_map, int max_cells);

TEST(steps_deepstate_test,can_source_cell_disperse_test){
  RInside R;
  std::cout << "input starts" << std::endl;
  IntegerVector source_y(1);
  source_y[0]  = RcppDeepState_int();
  qs::c_qsave(source_y,"/home/akhila/fuzzer_packages/fuzzedpackages/steps/inst/testfiles/can_source_cell_disperse/inputs/source_y.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "source_y values: "<< source_y << std::endl;
  IntegerVector source_x(1);
  source_x[0]  = RcppDeepState_int();
  qs::c_qsave(source_x,"/home/akhila/fuzzer_packages/fuzzedpackages/steps/inst/testfiles/can_source_cell_disperse/inputs/source_x.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "source_x values: "<< source_x << std::endl;
  NumericMatrix iterative_population_state  = RcppDeepState_NumericMatrix();
  qs::c_qsave(iterative_population_state,"/home/akhila/fuzzer_packages/fuzzedpackages/steps/inst/testfiles/can_source_cell_disperse/inputs/iterative_population_state.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "iterative_population_state values: "<< iterative_population_state << std::endl;
  NumericMatrix future_population_state  = RcppDeepState_NumericMatrix();
  qs::c_qsave(future_population_state,"/home/akhila/fuzzer_packages/fuzzedpackages/steps/inst/testfiles/can_source_cell_disperse/inputs/future_population_state.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "future_population_state values: "<< future_population_state << std::endl;
  NumericMatrix carrying_capacity_available  = RcppDeepState_NumericMatrix();
  qs::c_qsave(carrying_capacity_available,"/home/akhila/fuzzer_packages/fuzzedpackages/steps/inst/testfiles/can_source_cell_disperse/inputs/carrying_capacity_available.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "carrying_capacity_available values: "<< carrying_capacity_available << std::endl;
  NumericMatrix permeability_map  = RcppDeepState_NumericMatrix();
  qs::c_qsave(permeability_map,"/home/akhila/fuzzer_packages/fuzzedpackages/steps/inst/testfiles/can_source_cell_disperse/inputs/permeability_map.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "permeability_map values: "<< permeability_map << std::endl;
  IntegerVector max_cells(1);
  max_cells[0]  = RcppDeepState_int();
  qs::c_qsave(max_cells,"/home/akhila/fuzzer_packages/fuzzedpackages/steps/inst/testfiles/can_source_cell_disperse/inputs/max_cells.qs",
		"high", "zstd", 1, 15, true, 1);
  std::cout << "max_cells values: "<< max_cells << std::endl;
  std::cout << "input ends" << std::endl;
  try{
    can_source_cell_disperse(source_y[0],source_x[0],iterative_population_state,future_population_state,carrying_capacity_available,permeability_map,max_cells[0]);
  }
  catch(Rcpp::exception& e){
    std::cout<<"Exception Handled"<<std::endl;
  }
}
