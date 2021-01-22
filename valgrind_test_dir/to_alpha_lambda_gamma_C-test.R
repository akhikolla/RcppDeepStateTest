function (mu, sd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["to_alpha_lambda_gamma_C"]][[length(e[["to_alpha_lambda_gamma_C"]]) + 
        1]] <- list(mu = mu, sd = sd)
    .Call("_mixR_to_alpha_lambda_gamma_C", mu, sd)
}
