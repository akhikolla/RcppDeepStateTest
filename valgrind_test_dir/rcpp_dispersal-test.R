function (starting_population_state, potential_carrying_capacity, 
    permeability_map, max_cells, dispersal_proportion) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcpp_dispersal"]][[length(e[["rcpp_dispersal"]]) + 1]] <- list(starting_population_state = starting_population_state, 
        potential_carrying_capacity = potential_carrying_capacity, 
        permeability_map = permeability_map, max_cells = max_cells, 
        dispersal_proportion = dispersal_proportion)
    .Call("_steps_rcpp_dispersal", PACKAGE = "steps", starting_population_state, 
        potential_carrying_capacity, permeability_map, max_cells, 
        dispersal_proportion)
}
