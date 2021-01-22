function (a, mu, exp_mu) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_log_a_exp"]][[length(e[["cpp_log_a_exp"]]) + 1]] <- list(a = a, 
        mu = mu, exp_mu = exp_mu)
    .Call("_fixest_cpp_log_a_exp", a, mu, exp_mu)
}
