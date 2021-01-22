function (nsites, theta, sigma2, y, theta_tune, offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["poissonindepupdateMALA"]][[length(e[["poissonindepupdateMALA"]]) + 
        1]] <- list(nsites = nsites, theta = theta, sigma2 = sigma2, 
        y = y, theta_tune = theta_tune, offset = offset)
    .Call("_CARBayes_poissonindepupdateMALA", nsites, theta, 
        sigma2, y, theta_tune, offset)
}
