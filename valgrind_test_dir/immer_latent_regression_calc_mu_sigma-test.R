function (X, group, G, beta, gamma) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_latent_regression_calc_mu_sigma"]][[length(e[["immer_latent_regression_calc_mu_sigma"]]) + 
        1]] <- list(X = X, group = group, G = G, beta = beta, 
        gamma = gamma)
    .Call("_immer_immer_latent_regression_calc_mu_sigma", PACKAGE = "immer", 
        X, group, G, beta, gamma)
}
