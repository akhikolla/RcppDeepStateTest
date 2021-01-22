function (beta_tilde, normalization, lambda, alpha) 
{
    e <- get("data.env", .GlobalEnv)
    e[["soft_threshold"]][[length(e[["soft_threshold"]]) + 1]] <- list(beta_tilde = beta_tilde, 
        normalization = normalization, lambda = lambda, alpha = alpha)
    .Call("_xyz_soft_threshold", beta_tilde, normalization, lambda, 
        alpha)
}
