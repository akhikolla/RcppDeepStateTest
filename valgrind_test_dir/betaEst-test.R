function (fam_group, alpha, dtime, delta, g, var, lower, upper) 
{
    e <- get("data.env", .GlobalEnv)
    e[["betaEst"]][[length(e[["betaEst"]]) + 1]] <- list(fam_group = fam_group, 
        alpha = alpha, dtime = dtime, delta = delta, g = g, var = var, 
        lower = lower, upper = upper)
    .Call("_lclGWAS_betaEst", PACKAGE = "lclGWAS", fam_group, 
        alpha, dtime, delta, g, var, lower, upper)
}
