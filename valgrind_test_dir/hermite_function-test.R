function (N, x, normalization) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hermite_function"]][[length(e[["hermite_function"]]) + 
        1]] <- list(N = N, x = x, normalization = normalization)
    .Call("_hermiter_hermite_function", N, x, normalization)
}
