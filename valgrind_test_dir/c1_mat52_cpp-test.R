function (X, x, sigma, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c1_mat52_cpp"]][[length(e[["c1_mat52_cpp"]]) + 1]] <- list(X = X, 
        x = x, sigma = sigma, W = W)
    .Call("_hetGP_c1_mat52_cpp", PACKAGE = "hetGP", X, x, sigma, 
        W)
}
