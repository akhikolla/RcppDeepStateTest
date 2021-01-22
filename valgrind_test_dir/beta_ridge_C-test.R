function (X, Y, lambda_beta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["beta_ridge_C"]][[length(e[["beta_ridge_C"]]) + 1]] <- list(X = X, 
        Y = Y, lambda_beta = lambda_beta)
    .Call("_graphicalVAR_beta_ridge_C", X, Y, lambda_beta)
}
