function (a, b, mu = 0, sd = 1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["enorm_trunc"]][[length(e[["enorm_trunc"]]) + 1]] <- list(a = a, 
        b = b, mu = mu, sd = sd)
    .Call("_mixR_enorm_trunc", a, b, mu, sd)
}
