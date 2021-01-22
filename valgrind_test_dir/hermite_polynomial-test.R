function (N, x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hermite_polynomial"]][[length(e[["hermite_polynomial"]]) + 
        1]] <- list(N = N, x = x)
    .Call("_hermiter_hermite_polynomial", N, x)
}
