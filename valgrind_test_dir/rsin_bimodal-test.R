function (n, k1, k2, k3, mu1, mu2, kappa_opt, log_I0_kappa_opt, 
    logK, log_const_vmsin, mode_1, mode_2, vmpropn, unifpropn) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rsin_bimodal"]][[length(e[["rsin_bimodal"]]) + 1]] <- list(n = n, 
        k1 = k1, k2 = k2, k3 = k3, mu1 = mu1, mu2 = mu2, kappa_opt = kappa_opt, 
        log_I0_kappa_opt = log_I0_kappa_opt, logK = logK, log_const_vmsin = log_const_vmsin, 
        mode_1 = mode_1, mode_2 = mode_2, vmpropn = vmpropn, 
        unifpropn = unifpropn)
    .Call("_BAMBI_rsin_bimodal", n, k1, k2, k3, mu1, mu2, kappa_opt, 
        log_I0_kappa_opt, logK, log_const_vmsin, mode_1, mode_2, 
        vmpropn, unifpropn)
}
