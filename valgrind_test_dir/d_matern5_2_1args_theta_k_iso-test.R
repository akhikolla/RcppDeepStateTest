function (X1, theta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["d_matern5_2_1args_theta_k_iso"]][[length(e[["d_matern5_2_1args_theta_k_iso"]]) + 
        1]] <- list(X1 = X1, theta = theta)
    .Call("_hetGP_d_matern5_2_1args_theta_k_iso", PACKAGE = "hetGP", 
        X1, theta)
}
