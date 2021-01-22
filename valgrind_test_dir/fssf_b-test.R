function (d, nMax, N = -1L, eps = 0.5) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fssf_b"]][[length(e[["fssf_b"]]) + 1]] <- list(d = d, 
        nMax = nMax, N = N, eps = eps)
    .Call("_FSSF_fssf_b", d, nMax, N, eps)
}
