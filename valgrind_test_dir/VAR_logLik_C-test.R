function (X, Y, kappa, beta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["VAR_logLik_C"]][[length(e[["VAR_logLik_C"]]) + 1]] <- list(X = X, 
        Y = Y, kappa = kappa, beta = beta)
    .Call("_graphicalVAR_VAR_logLik_C", X, Y, kappa, beta)
}
