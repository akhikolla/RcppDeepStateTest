function (k, Ft, Fn, Tr, K) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fpr_fs_calc"]][[length(e[["fpr_fs_calc"]]) + 1]] <- list(k = k, 
        Ft = Ft, Fn = Fn, Tr = Tr, K = K)
    .Call("_forestControl_fpr_fs_calc", PACKAGE = "forestControl", 
        k, Ft, Fn, Tr, K)
}
