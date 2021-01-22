function (fam_group, alpha, dtime, delta, g, beta, lower, upper) 
{
    e <- get("data.env", .GlobalEnv)
    e[["varEst"]][[length(e[["varEst"]]) + 1]] <- list(fam_group = fam_group, 
        alpha = alpha, dtime = dtime, delta = delta, g = g, beta = beta, 
        lower = lower, upper = upper)
    .Call("_lclGWAS_varEst", PACKAGE = "lclGWAS", fam_group, 
        alpha, dtime, delta, g, beta, lower, upper)
}
