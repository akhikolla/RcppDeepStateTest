function (dtime, delta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["alphaEst"]][[length(e[["alphaEst"]]) + 1]] <- list(dtime = dtime, 
        delta = delta)
    .Call("_lclGWAS_alphaEst", PACKAGE = "lclGWAS", dtime, delta)
}
