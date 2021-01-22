function (x, n, increment, alignCode) 
{
    e <- get("data.env", .GlobalEnv)
    e[["roll_sd_numeric_vector"]][[length(e[["roll_sd_numeric_vector"]]) + 
        1]] <- list(x = x, n = n, increment = increment, alignCode = alignCode)
    .Call("_seismicRoll_roll_sd_numeric_vector", x, n, increment, 
        alignCode)
}
