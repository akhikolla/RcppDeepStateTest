function (GlobalMat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["k_chol"]][[length(e[["k_chol"]]) + 1]] <- list(GlobalMat = GlobalMat)
    .Call("_krige_k_chol", GlobalMat)
}
