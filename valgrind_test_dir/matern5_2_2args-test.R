function (X1, X2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["matern5_2_2args"]][[length(e[["matern5_2_2args"]]) + 
        1]] <- list(X1 = X1, X2 = X2)
    .Call("_hetGP_matern5_2_2args", PACKAGE = "hetGP", X1, X2)
}
