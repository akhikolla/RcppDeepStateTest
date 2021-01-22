function (L, v) 
{
    e <- get("data.env", .GlobalEnv)
    e[["chol_downdate"]][[length(e[["chol_downdate"]]) + 1]] <- list(L = L, 
        v = v)
    .Call("_Benchmarking_chol_downdate", L, v)
}
