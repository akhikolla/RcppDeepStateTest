function (X, x, sigma) 
{
    e <- get("data.env", .GlobalEnv)
    e[["d_gauss_cpp"]][[length(e[["d_gauss_cpp"]]) + 1]] <- list(X = X, 
        x = x, sigma = sigma)
    .Call("_hetGP_d_gauss_cpp", PACKAGE = "hetGP", X, x, sigma)
}
