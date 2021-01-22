function (n, lambda, range) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Cexptr"]][[length(e[["Cexptr"]]) + 1]] <- list(n = n, 
        lambda = lambda, range = range)
    .Call("_RGeode_Cexptr", PACKAGE = "RGeode", n, lambda, range)
}
