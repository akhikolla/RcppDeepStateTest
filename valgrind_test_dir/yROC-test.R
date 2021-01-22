function (zeta, mu, lambdaP, nuP, lesDistr) 
{
    e <- get("data.env", .GlobalEnv)
    e[["yROC"]][[length(e[["yROC"]]) + 1]] <- list(zeta = zeta, 
        mu = mu, lambdaP = lambdaP, nuP = nuP, lesDistr = lesDistr)
    .Call("_RJafroc_yROC", PACKAGE = "RJafroc", zeta, mu, lambdaP, 
        nuP, lesDistr)
}
