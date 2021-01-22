function (X1, kt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["d_matern5_2_1args_kthetag"]][[length(e[["d_matern5_2_1args_kthetag"]]) + 
        1]] <- list(X1 = X1, kt = kt)
    .Call("_hetGP_d_matern5_2_1args_kthetag", PACKAGE = "hetGP", 
        X1, kt)
}
