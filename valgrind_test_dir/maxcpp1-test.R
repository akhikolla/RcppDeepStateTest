function (tau, x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["maxcpp1"]][[length(e[["maxcpp1"]]) + 1]] <- list(tau = tau, 
        x = x, y = y)
    .Call("_timma_maxcpp1", PACKAGE = "timma", tau, x, y)
}
