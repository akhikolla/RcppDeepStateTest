function (k1, k2, k3) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vmcos_var_corr_anltc"]][[length(e[["vmcos_var_corr_anltc"]]) + 
        1]] <- list(k1 = k1, k2 = k2, k3 = k3)
    .Call("_BAMBI_vmcos_var_corr_anltc", k1, k2, k3)
}
