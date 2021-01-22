function (x, pi, mu, sd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["expZ_norm_C"]][[length(e[["expZ_norm_C"]]) + 1]] <- list(x = x, 
        pi = pi, mu = mu, sd = sd)
    .Call("_mixR_expZ_norm_C", x, pi, mu, sd)
}
