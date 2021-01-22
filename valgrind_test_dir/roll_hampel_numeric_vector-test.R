function (x, n, increment) 
{
    e <- get("data.env", .GlobalEnv)
    e[["roll_hampel_numeric_vector"]][[length(e[["roll_hampel_numeric_vector"]]) + 
        1]] <- list(x = x, n = n, increment = increment)
    .Call("_seismicRoll_roll_hampel_numeric_vector", x, n, increment)
}
