function (X, group, G, pars, theta, weights, like) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_latent_regression_calc_individual_likelihood"]][[length(e[["immer_latent_regression_calc_individual_likelihood"]]) + 
        1]] <- list(X = X, group = group, G = G, pars = pars, 
        theta = theta, weights = weights, like = like)
    .Call("_immer_immer_latent_regression_calc_individual_likelihood", 
        PACKAGE = "immer", X, group, G, pars, theta, weights, 
        like)
}
