function (source_y, source_x, iterative_population_state, future_population_state, 
    carrying_capacity_available, permeability_map, max_cells) 
{
    e <- get("data.env", .GlobalEnv)
    e[["can_source_cell_disperse"]][[length(e[["can_source_cell_disperse"]]) + 
        1]] <- list(source_y = source_y, source_x = source_x, 
        iterative_population_state = iterative_population_state, 
        future_population_state = future_population_state, carrying_capacity_available = carrying_capacity_available, 
        permeability_map = permeability_map, max_cells = max_cells)
    .Call("_steps_can_source_cell_disperse", PACKAGE = "steps", 
        source_y, source_x, iterative_population_state, future_population_state, 
        carrying_capacity_available, permeability_map, max_cells)
}
