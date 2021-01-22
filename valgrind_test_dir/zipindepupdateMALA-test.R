function (nsites, theta, sigma2, y, theta_tune, offset, poiind) 
{
    e <- get("data.env", .GlobalEnv)
    e[["zipindepupdateMALA"]][[length(e[["zipindepupdateMALA"]]) + 
        1]] <- list(nsites = nsites, theta = theta, sigma2 = sigma2, 
        y = y, theta_tune = theta_tune, offset = offset, poiind = poiind)
    .Call("_CARBayes_zipindepupdateMALA", nsites, theta, sigma2, 
        y, theta_tune, offset, poiind)
}
