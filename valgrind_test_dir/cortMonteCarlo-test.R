function (z, min, max, N) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cortMonteCarlo"]][[length(e[["cortMonteCarlo"]]) + 1]] <- list(z = z, 
        min = min, max = max, N = N)
    .Call("_cort_cortMonteCarlo", z, min, max, N)
}
