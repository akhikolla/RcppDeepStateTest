function (zeta, mu, nuP, lesDistr, lesWghtDistr) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ywAFROC"]][[length(e[["ywAFROC"]]) + 1]] <- list(zeta = zeta, 
        mu = mu, nuP = nuP, lesDistr = lesDistr, lesWghtDistr = lesWghtDistr)
    .Call("_RJafroc_ywAFROC", PACKAGE = "RJafroc", zeta, mu, 
        nuP, lesDistr, lesWghtDistr)
}
