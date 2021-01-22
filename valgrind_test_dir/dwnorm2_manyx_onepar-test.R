function (x, k1, k2, k3, mu1, mu2, omega_2pi) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dwnorm2_manyx_onepar"]][[length(e[["dwnorm2_manyx_onepar"]]) + 
        1]] <- list(x = x, k1 = k1, k2 = k2, k3 = k3, mu1 = mu1, 
        mu2 = mu2, omega_2pi = omega_2pi)
    .Call("_BAMBI_dwnorm2_manyx_onepar", x, k1, k2, k3, mu1, 
        mu2, omega_2pi)
}
