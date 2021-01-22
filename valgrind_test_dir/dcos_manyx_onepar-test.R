function (x, k1, k2, k3, mu1, mu2, l_const) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dcos_manyx_onepar"]][[length(e[["dcos_manyx_onepar"]]) + 
        1]] <- list(x = x, k1 = k1, k2 = k2, k3 = k3, mu1 = mu1, 
        mu2 = mu2, l_const = l_const)
    .Call("_BAMBI_dcos_manyx_onepar", x, k1, k2, k3, mu1, mu2, 
        l_const)
}
