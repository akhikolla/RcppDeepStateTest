function (X, Y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["absolute_covariates"]][[length(e[["absolute_covariates"]]) + 
        1]] <- list(X = X, Y = Y)
    .Call("_xyz_absolute_covariates", X, Y)
}
