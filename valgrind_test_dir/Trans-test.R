function (M) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Trans"]][[length(e[["Trans"]]) + 1]] <- list(M = M)
    .Call("_Opt5PL_Trans", M)
}
