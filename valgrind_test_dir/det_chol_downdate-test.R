function (L, v) 
{
    e <- get("data.env", .GlobalEnv)
    e[["det_chol_downdate"]][[length(e[["det_chol_downdate"]]) + 
        1]] <- list(L = L, v = v)
    .Call("_Benchmarking_det_chol_downdate", L, v)
}
