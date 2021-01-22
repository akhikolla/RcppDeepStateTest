function (nsites, theta, sigma2, y, failures, theta_tune, offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["binomialindepupdateRW"]][[length(e[["binomialindepupdateRW"]]) + 
        1]] <- list(nsites = nsites, theta = theta, sigma2 = sigma2, 
        y = y, failures = failures, theta_tune = theta_tune, 
        offset = offset)
    .Call("_CARBayes_binomialindepupdateRW", nsites, theta, sigma2, 
        y, failures, theta_tune, offset)
}
