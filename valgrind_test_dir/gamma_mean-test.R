function (outgamma, start) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gamma_mean"]][[length(e[["gamma_mean"]]) + 1]] <- list(outgamma = outgamma, 
        start = start)
    .Call("_icensmis_gamma_mean", PACKAGE = "icensmis", outgamma, 
        start)
}
