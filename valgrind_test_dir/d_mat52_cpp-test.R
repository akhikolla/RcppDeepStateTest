function (X, x, sigma) 
{
    e <- get("data.env", .GlobalEnv)
    e[["d_mat52_cpp"]][[length(e[["d_mat52_cpp"]]) + 1]] <- list(X = X, 
        x = x, sigma = sigma)
    .Call("_hetGP_d_mat52_cpp", PACKAGE = "hetGP", X, x, sigma)
}
