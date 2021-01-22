function (n, a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gc"]][[length(e[["gc"]]) + 1]] <- list(n = n, a = a)
    .Call("_BNSL_gc", n, a)
}
