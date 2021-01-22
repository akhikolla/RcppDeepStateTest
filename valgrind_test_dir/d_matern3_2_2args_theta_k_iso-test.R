function (X1, X2, theta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["d_matern3_2_2args_theta_k_iso"]][[length(e[["d_matern3_2_2args_theta_k_iso"]]) + 
        1]] <- list(X1 = X1, X2 = X2, theta = theta)
    .Call("_hetGP_d_matern3_2_2args_theta_k_iso", PACKAGE = "hetGP", 
        X1, X2, theta)
}
