function (Mu, sigma) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mi_mat32_cpp"]][[length(e[["mi_mat32_cpp"]]) + 1]] <- list(Mu = Mu, 
        sigma = sigma)
    .Call("_hetGP_mi_mat32_cpp", PACKAGE = "hetGP", Mu, sigma)
}
