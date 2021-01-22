function (GlobalMat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["k_inv"]][[length(e[["k_inv"]]) + 1]] <- list(GlobalMat = GlobalMat)
    .Call("_krige_k_inv", GlobalMat)
}
