function (L, v) 
{
    e <- get("data.env", .GlobalEnv)
    e[["chol_downdate2"]][[length(e[["chol_downdate2"]]) + 1]] <- list(L = L, 
        v = v)
    .Call("_Benchmarking_chol_downdate2", L, v)
}
