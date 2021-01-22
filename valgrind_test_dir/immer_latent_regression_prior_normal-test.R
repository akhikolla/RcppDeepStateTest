function (mu, sigma, theta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_latent_regression_prior_normal"]][[length(e[["immer_latent_regression_prior_normal"]]) + 
        1]] <- list(mu = mu, sigma = sigma, theta = theta)
    .Call("_immer_immer_latent_regression_prior_normal", PACKAGE = "immer", 
        mu, sigma, theta)
}
