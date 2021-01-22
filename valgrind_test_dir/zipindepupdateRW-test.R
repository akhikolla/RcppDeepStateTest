function (nsites, theta, sigma2, y, theta_tune, offset, poiind) 
{
    e <- get("data.env", .GlobalEnv)
    e[["zipindepupdateRW"]][[length(e[["zipindepupdateRW"]]) + 
        1]] <- list(nsites = nsites, theta = theta, sigma2 = sigma2, 
        y = y, theta_tune = theta_tune, offset = offset, poiind = poiind)
    .Call("_CARBayes_zipindepupdateRW", nsites, theta, sigma2, 
        y, theta_tune, offset, poiind)
}
