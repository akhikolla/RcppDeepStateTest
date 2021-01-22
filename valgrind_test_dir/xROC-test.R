function (zeta, lambdaP) 
{
    e <- get("data.env", .GlobalEnv)
    e[["xROC"]][[length(e[["xROC"]]) + 1]] <- list(zeta = zeta, 
        lambdaP = lambdaP)
    .Call("_RJafroc_xROC", PACKAGE = "RJafroc", zeta, lambdaP)
}
