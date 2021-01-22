function (x, n_sta, n_lta, increment) 
{
    e <- get("data.env", .GlobalEnv)
    e[["roll_stalta_numeric_vector"]][[length(e[["roll_stalta_numeric_vector"]]) + 
        1]] <- list(x = x, n_sta = n_sta, n_lta = n_lta, increment = increment)
    .Call("_seismicRoll_roll_stalta_numeric_vector", x, n_sta, 
        n_lta, increment)
}
