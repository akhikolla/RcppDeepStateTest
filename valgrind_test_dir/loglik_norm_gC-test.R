function (data, pi, mu, sd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["loglik_norm_gC"]][[length(e[["loglik_norm_gC"]]) + 1]] <- list(data = data, 
        pi = pi, mu = mu, sd = sd)
    .Call("_mixR_loglik_norm_gC", data, pi, mu, sd)
}
