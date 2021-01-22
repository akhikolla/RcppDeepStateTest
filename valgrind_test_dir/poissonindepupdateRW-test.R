function (nsites, theta, sigma2, y, theta_tune, offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["poissonindepupdateRW"]][[length(e[["poissonindepupdateRW"]]) + 
        1]] <- list(nsites = nsites, theta = theta, sigma2 = sigma2, 
        y = y, theta_tune = theta_tune, offset = offset)
    .Call("_CARBayes_poissonindepupdateRW", nsites, theta, sigma2, 
        y, theta_tune, offset)
}
