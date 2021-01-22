function (nsites, theta, sigma2, y, failures, trials, theta_tune, 
    offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["binomialindepupdateMALA"]][[length(e[["binomialindepupdateMALA"]]) + 
        1]] <- list(nsites = nsites, theta = theta, sigma2 = sigma2, 
        y = y, failures = failures, trials = trials, theta_tune = theta_tune, 
        offset = offset)
    .Call("_CARBayes_binomialindepupdateMALA", nsites, theta, 
        sigma2, y, failures, trials, theta_tune, offset)
}
