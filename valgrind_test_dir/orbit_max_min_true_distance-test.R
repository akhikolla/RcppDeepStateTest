function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["orbit_max_min_true_distance"]][[length(e[["orbit_max_min_true_distance"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
