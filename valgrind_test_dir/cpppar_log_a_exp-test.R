function (nthreads, a, mu, exp_mu) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpppar_log_a_exp"]][[length(e[["cpppar_log_a_exp"]]) + 
        1]] <- list(nthreads = nthreads, a = a, mu = mu, exp_mu = exp_mu)
    .Call("_fixest_cpppar_log_a_exp", nthreads, a, mu, exp_mu)
}
