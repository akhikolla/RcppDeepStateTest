function (k1, k2, k3) 
{
    e <- get("data.env", .GlobalEnv)
    e[["d_const_vmcos_anltc"]][[length(e[["d_const_vmcos_anltc"]]) + 
        1]] <- list(k1 = k1, k2 = k2, k3 = k3)
    .Call("_BAMBI_d_const_vmcos_anltc", k1, k2, k3)
}
