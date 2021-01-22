function (X1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["matern3_2_1args"]][[length(e[["matern3_2_1args"]]) + 
        1]] <- list(X1 = X1)
    .Call("_hetGP_matern3_2_1args", PACKAGE = "hetGP", X1)
}
