function (alpha, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["to_mu_sd_gamma_C"]][[length(e[["to_mu_sd_gamma_C"]]) + 
        1]] <- list(alpha = alpha, lambda = lambda)
    .Call("_mixR_to_mu_sd_gamma_C", alpha, lambda)
}
