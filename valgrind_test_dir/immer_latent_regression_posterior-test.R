function (like, prior, weights) 
{
    e <- get("data.env", .GlobalEnv)
    e[["immer_latent_regression_posterior"]][[length(e[["immer_latent_regression_posterior"]]) + 
        1]] <- list(like = like, prior = prior, weights = weights)
    .Call("_immer_immer_latent_regression_posterior", PACKAGE = "immer", 
        like, prior, weights)
}
