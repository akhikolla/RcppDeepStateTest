function (theta, moves, n_zones) 
{
    e <- get("data.env", .GlobalEnv)
    e[["clean_moves_matrix"]][[length(e[["clean_moves_matrix"]]) + 
        1]] <- list(theta = theta, moves = moves, n_zones = n_zones)
    .Call("_SpatialEpi_clean_moves_matrix", PACKAGE = "SpatialEpi", 
        theta, moves, n_zones)
}
