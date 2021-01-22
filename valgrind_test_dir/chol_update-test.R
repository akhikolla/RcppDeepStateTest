function (L, v) 
{
    e <- get("data.env", .GlobalEnv)
    e[["chol_update"]][[length(e[["chol_update"]]) + 1]] <- list(L = L, 
        v = v)
    .Call("_Benchmarking_chol_update", L, v)
}
