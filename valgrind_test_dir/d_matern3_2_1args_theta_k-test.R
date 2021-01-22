function (X1, theta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["d_matern3_2_1args_theta_k"]][[length(e[["d_matern3_2_1args_theta_k"]]) + 
        1]] <- list(X1 = X1, theta = theta)
    .Call("_hetGP_d_matern3_2_1args_theta_k", PACKAGE = "hetGP", 
        X1, theta)
}
