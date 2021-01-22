function (N) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hermite_normalization"]][[length(e[["hermite_normalization"]]) + 
        1]] <- list(N = N)
    .Call("_hermiter_hermite_normalization", N)
}
