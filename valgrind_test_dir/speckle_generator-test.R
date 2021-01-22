function (rho, theta, dm, seeing, speckle_sigma, wind) 
{
    e <- get("data.env", .GlobalEnv)
    e[["speckle_generator"]][[length(e[["speckle_generator"]]) + 
        1]] <- list(rho = rho, theta = theta, dm = dm, seeing = seeing, 
        speckle_sigma = speckle_sigma, wind = wind)
    .Call("_specklestar_speckle_generator", PACKAGE = "specklestar", 
        rho, theta, dm, seeing, speckle_sigma, wind)
}
