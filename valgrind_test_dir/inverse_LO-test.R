function (L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["inverse_LO"]][[length(e[["inverse_LO"]]) + 1]] <- list(L = L)
    .Call("_Benchmarking_inverse_LO", L)
}
