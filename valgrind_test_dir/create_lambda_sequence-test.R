function (lambda_max, n_lambda, factor_eps_inv) 
{
    e <- get("data.env", .GlobalEnv)
    e[["create_lambda_sequence"]][[length(e[["create_lambda_sequence"]]) + 
        1]] <- list(lambda_max = lambda_max, n_lambda = n_lambda, 
        factor_eps_inv = factor_eps_inv)
    .Call("_xyz_create_lambda_sequence", lambda_max, n_lambda, 
        factor_eps_inv)
}
