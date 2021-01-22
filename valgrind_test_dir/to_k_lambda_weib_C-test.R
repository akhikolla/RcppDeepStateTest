function (mu, sd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["to_k_lambda_weib_C"]][[length(e[["to_k_lambda_weib_C"]]) + 
        1]] <- list(mu = mu, sd = sd)
    .Call("_mixR_to_k_lambda_weib_C", mu, sd)
}
