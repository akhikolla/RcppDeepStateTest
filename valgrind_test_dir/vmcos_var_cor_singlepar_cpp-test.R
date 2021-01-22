function (k1, k2, k3, uni_rand, ncores = 1L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["vmcos_var_cor_singlepar_cpp"]][[length(e[["vmcos_var_cor_singlepar_cpp"]]) + 
        1]] <- list(k1 = k1, k2 = k2, k3 = k3, uni_rand = uni_rand, 
        ncores = ncores)
    .Call("_BAMBI_vmcos_var_cor_singlepar_cpp", k1, k2, k3, uni_rand, 
        ncores)
}
