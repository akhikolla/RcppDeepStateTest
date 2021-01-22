function (X, group, G, pars, theta, weights, like, h) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_latent_regression_vcov_xpd"]][[length(e[["immer_latent_regression_vcov_xpd"]]) + 
        1]] <- list(X = X, group = group, G = G, pars = pars, 
        theta = theta, weights = weights, like = like, h = h)
    .Call("_immer_immer_latent_regression_vcov_xpd", PACKAGE = "immer", 
        X, group, G, pars, theta, weights, like, h)
}
