function (zeta, mu, lambdaP, nuP, lesDistr) 
{
    e <- get("data.env", .GlobalEnv)
    e[["yROCVect"]][[length(e[["yROCVect"]]) + 1]] <- list(zeta = zeta, 
        mu = mu, lambdaP = lambdaP, nuP = nuP, lesDistr = lesDistr)
    .Call("_RJafroc_yROCVect", PACKAGE = "RJafroc", zeta, mu, 
        lambdaP, nuP, lesDistr)
}
