function (k, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["to_mu_sd_weib_C"]][[length(e[["to_mu_sd_weib_C"]]) + 
        1]] <- list(k = k, lambda = lambda)
    .Call("_mixR_to_mu_sd_weib_C", k, lambda)
}
