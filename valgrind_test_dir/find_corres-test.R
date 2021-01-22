function (X0, X) 
{
    e <- get("data.env", .GlobalEnv)
    e[["find_corres"]][[length(e[["find_corres"]]) + 1]] <- list(X0 = X0, 
        X = X)
    .Call("_hetGP_find_corres", PACKAGE = "hetGP", X0, X)
}
