function (mu, lambdaP, nuP, lesDistr, zeta, fb, tb) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RsmInner"]][[length(e[["RsmInner"]]) + 1]] <- list(mu = mu, 
        lambdaP = lambdaP, nuP = nuP, lesDistr = lesDistr, zeta = zeta, 
        fb = fb, tb = tb)
    .Call("_RJafroc_RsmInner", PACKAGE = "RJafroc", mu, lambdaP, 
        nuP, lesDistr, zeta, fb, tb)
}
