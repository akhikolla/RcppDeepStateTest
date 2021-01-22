function (x, k1, k2, k3, mu1, mu2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ldsin_manyx_onepar"]][[length(e[["ldsin_manyx_onepar"]]) + 
        1]] <- list(x = x, k1 = k1, k2 = k2, k3 = k3, mu1 = mu1, 
        mu2 = mu2)
    .Call("_BAMBI_ldsin_manyx_onepar", x, k1, k2, k3, mu1, mu2)
}
