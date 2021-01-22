function (tau, x, y, j) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mincpp"]][[length(e[["mincpp"]]) + 1]] <- list(tau = tau, 
        x = x, y = y, j = j)
    .Call("_timma_mincpp", PACKAGE = "timma", tau, x, y, j)
}
