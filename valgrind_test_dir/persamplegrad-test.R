function (fx, y, n, group) 
{
    e <- get("data.env", .GlobalEnv)
    e[["persamplegrad"]][[length(e[["persamplegrad"]]) + 1]] <- list(fx = fx, 
        y = y, n = n, group = group)
    .Call("_clogitboost_persamplegrad", PACKAGE = "clogitboost", 
        fx, y, n, group)
}
