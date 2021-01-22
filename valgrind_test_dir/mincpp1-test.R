function (tau, x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mincpp1"]][[length(e[["mincpp1"]]) + 1]] <- list(tau = tau, 
        x = x, y = y)
    .Call("_timma_mincpp1", PACKAGE = "timma", tau, x, y)
}
