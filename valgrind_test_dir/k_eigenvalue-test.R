function (GlobalMat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["k_eigenvalue"]][[length(e[["k_eigenvalue"]]) + 1]] <- list(GlobalMat = GlobalMat)
    .Call("_krige_k_eigenvalue", GlobalMat)
}
