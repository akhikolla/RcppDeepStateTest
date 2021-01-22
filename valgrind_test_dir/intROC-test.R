function (FPF, mu, lambdaP, nuP, lesDistr) 
{
    e <- get("data.env", .GlobalEnv)
    e[["intROC"]][[length(e[["intROC"]]) + 1]] <- list(FPF = FPF, 
        mu = mu, lambdaP = lambdaP, nuP = nuP, lesDistr = lesDistr)
    .Call("_RJafroc_intROC", PACKAGE = "RJafroc", FPF, mu, lambdaP, 
        nuP, lesDistr)
}
