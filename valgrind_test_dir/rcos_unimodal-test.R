function (n, k1, k2, k3, mu1, mu2, kappa_opt, log_I0_kappa_opt, 
    logK, log_const_vmcos) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rcos_unimodal"]][[length(e[["rcos_unimodal"]]) + 1]] <- list(n = n, 
        k1 = k1, k2 = k2, k3 = k3, mu1 = mu1, mu2 = mu2, kappa_opt = kappa_opt, 
        log_I0_kappa_opt = log_I0_kappa_opt, logK = logK, log_const_vmcos = log_const_vmcos)
    .Call("_BAMBI_rcos_unimodal", n, k1, k2, k3, mu1, mu2, kappa_opt, 
        log_I0_kappa_opt, logK, log_const_vmcos)
}
