function (fx, y, n, group) 
{
    e <- get("data.env", .GlobalEnv)
    e[["likelihood"]][[length(e[["likelihood"]]) + 1]] <- list(fx = fx, 
        y = y, n = n, group = group)
    .Call("_clogitboost_likelihood", PACKAGE = "clogitboost", 
        fx, y, n, group)
}
