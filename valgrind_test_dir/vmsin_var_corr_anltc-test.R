function (k1, k2, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vmsin_var_corr_anltc"]][[length(e[["vmsin_var_corr_anltc"]]) + 
        1]] <- list(k1 = k1, k2 = k2, lambda = lambda)
    .Call("_BAMBI_vmsin_var_corr_anltc", k1, k2, lambda)
}
