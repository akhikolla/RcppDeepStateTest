function (X, group, G, pars, theta, weights, like, pos1, h1, 
    pos2, h2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_latent_regression_calc_individual_likelihood_increment"]][[length(e[["immer_latent_regression_calc_individual_likelihood_increment"]]) + 
        1]] <- list(X = X, group = group, G = G, pars = pars, 
        theta = theta, weights = weights, like = like, pos1 = pos1, 
        h1 = h1, pos2 = pos2, h2 = h2)
    .Call("_immer_immer_latent_regression_calc_individual_likelihood_increment", 
        PACKAGE = "immer", X, group, G, pars, theta, weights, 
        like, pos1, h1, pos2, h2)
}
