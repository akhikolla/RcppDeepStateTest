function (tau, x, y, j) 
{
    e <- get("data.env", .GlobalEnv)
    e[["maxcpp"]][[length(e[["maxcpp"]]) + 1]] <- list(tau = tau, 
        x = x, y = y, j = j)
    .Call("_timma_maxcpp", PACKAGE = "timma", tau, x, y, j)
}
