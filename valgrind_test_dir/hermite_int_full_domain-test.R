function (N) 
{
    e <- get("data.env", .GlobalEnv)
    e[["hermite_int_full_domain"]][[length(e[["hermite_int_full_domain"]]) + 
        1]] <- list(N = N)
    .Call("_hermiter_hermite_int_full_domain", N)
}
