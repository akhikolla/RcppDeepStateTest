function (tau, x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sumcpp1"]][[length(e[["sumcpp1"]]) + 1]] <- list(tau = tau, 
        x = x, y = y)
    .Call("_timma_sumcpp1", PACKAGE = "timma", tau, x, y)
}
