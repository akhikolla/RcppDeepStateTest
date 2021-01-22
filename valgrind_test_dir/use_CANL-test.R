function (mat, N, w0, k, eps) 
{
    e <- get("data.env", .GlobalEnv)
    e[["use_CANL"]][[length(e[["use_CANL"]]) + 1]] <- list(mat = mat, 
        N = N, w0 = w0, k = k, eps = eps)
    .Call("_abcADM_use_CANL", mat, N, w0, k, eps)
}
