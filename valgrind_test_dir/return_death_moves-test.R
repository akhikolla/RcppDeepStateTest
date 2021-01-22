function (theta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["return_death_moves"]][[length(e[["return_death_moves"]]) + 
        1]] <- list(theta = theta)
    .Call("_SpatialEpi_return_death_moves", PACKAGE = "SpatialEpi", 
        theta)
}
