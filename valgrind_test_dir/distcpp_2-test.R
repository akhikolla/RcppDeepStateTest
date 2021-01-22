function (X1, X2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["distcpp_2"]][[length(e[["distcpp_2"]]) + 1]] <- list(X1 = X1, 
        X2 = X2)
    .Call("_GPareto_distcpp_2", X1, X2)
}
