function (Mu, sigma) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mi_mat52_cpp"]][[length(e[["mi_mat52_cpp"]]) + 1]] <- list(Mu = Mu, 
        sigma = sigma)
    .Call("_hetGP_mi_mat52_cpp", PACKAGE = "hetGP", Mu, sigma)
}
