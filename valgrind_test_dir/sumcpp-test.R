function (tau, x, y, j) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sumcpp"]][[length(e[["sumcpp"]]) + 1]] <- list(tau = tau, 
        x = x, y = y, j = j)
    .Call("_timma_sumcpp", PACKAGE = "timma", tau, x, y, j)
}
