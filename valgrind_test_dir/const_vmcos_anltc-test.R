function (k1, k2, k3) 
{
    e <- get("data.env", .GlobalEnv)
    e[["const_vmcos_anltc"]][[length(e[["const_vmcos_anltc"]]) + 
        1]] <- list(k1 = k1, k2 = k2, k3 = k3)
    .Call("_BAMBI_const_vmcos_anltc", k1, k2, k3)
}
