function (X, x, sigma, W) 
{
    e <- get("data.env", .GlobalEnv)
    e[["c1_gauss_cpp"]][[length(e[["c1_gauss_cpp"]]) + 1]] <- list(X = X, 
        x = x, sigma = sigma, W = W)
    .Call("_hetGP_c1_gauss_cpp", PACKAGE = "hetGP", X, x, sigma, 
        W)
}
