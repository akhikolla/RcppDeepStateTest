function (Ft, Fn, K, Tr, alpha) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sft_calc"]][[length(e[["sft_calc"]]) + 1]] <- list(Ft = Ft, 
        Fn = Fn, K = K, Tr = Tr, alpha = alpha)
    .Call("_forestControl_sft_calc", PACKAGE = "forestControl", 
        Ft, Fn, K, Tr, alpha)
}
