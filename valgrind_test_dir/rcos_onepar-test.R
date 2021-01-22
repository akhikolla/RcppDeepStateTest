function (n, k1, k2, k3, mu1, mu2, I_upper_bd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcos_onepar"]][[length(e[["rcos_onepar"]]) + 1]] <- list(n = n, 
        k1 = k1, k2 = k2, k3 = k3, mu1 = mu1, mu2 = mu2, I_upper_bd = I_upper_bd)
    .Call("_BAMBI_rcos_onepar", n, k1, k2, k3, mu1, mu2, I_upper_bd)
}
