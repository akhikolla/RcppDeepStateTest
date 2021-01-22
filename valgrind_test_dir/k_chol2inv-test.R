function (GlobalMat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["k_chol2inv"]][[length(e[["k_chol2inv"]]) + 1]] <- list(GlobalMat = GlobalMat)
    .Call("_krige_k_chol2inv", GlobalMat)
}
