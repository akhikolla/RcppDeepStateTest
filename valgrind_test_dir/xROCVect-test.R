function (zeta, lambdaP) 
{
    e <- get("data.env", .GlobalEnv)
    e[["xROCVect"]][[length(e[["xROCVect"]]) + 1]] <- list(zeta = zeta, 
        lambdaP = lambdaP)
    .Call("_RJafroc_xROCVect", PACKAGE = "RJafroc", zeta, lambdaP)
}
