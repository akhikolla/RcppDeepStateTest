function (k1, k2, k3, uni_rand, ncores = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["d_const_vmcos_mc"]][[length(e[["d_const_vmcos_mc"]]) + 
        1]] <- list(k1 = k1, k2 = k2, k3 = k3, uni_rand = uni_rand, 
        ncores = ncores)
    .Call("_BAMBI_d_const_vmcos_mc", k1, k2, k3, uni_rand, ncores)
}
