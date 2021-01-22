function (Mu, sigma) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mi_gauss_cpp"]][[length(e[["mi_gauss_cpp"]]) + 1]] <- list(Mu = Mu, 
        sigma = sigma)
    .Call("_hetGP_mi_gauss_cpp", PACKAGE = "hetGP", Mu, sigma)
}
