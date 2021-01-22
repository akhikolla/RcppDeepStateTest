function (id, time, nlag) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_lag_obs"]][[length(e[["cpp_lag_obs"]]) + 1]] <- list(id = id, 
        time = time, nlag = nlag)
    .Call("_fixest_cpp_lag_obs", id, time, nlag)
}
