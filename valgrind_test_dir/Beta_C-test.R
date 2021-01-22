function (kappa, beta, X, Y, lambda_beta, lambda_beta_mat, convergence, 
    maxit) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Beta_C"]][[length(e[["Beta_C"]]) + 1]] <- list(kappa = kappa, 
        beta = beta, X = X, Y = Y, lambda_beta = lambda_beta, 
        lambda_beta_mat = lambda_beta_mat, convergence = convergence, 
        maxit = maxit)
    .Call("_graphicalVAR_Beta_C", kappa, beta, X, Y, lambda_beta, 
        lambda_beta_mat, convergence, maxit)
}
