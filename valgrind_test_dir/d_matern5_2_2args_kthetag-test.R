function (X1, X2, kt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["d_matern5_2_2args_kthetag"]][[length(e[["d_matern5_2_2args_kthetag"]]) + 
        1]] <- list(X1 = X1, X2 = X2, kt = kt)
    .Call("_hetGP_d_matern5_2_2args_kthetag", PACKAGE = "hetGP", 
        X1, X2, kt)
}
