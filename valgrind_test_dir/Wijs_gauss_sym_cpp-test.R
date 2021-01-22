function (Mu, sigma) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Wijs_gauss_sym_cpp"]][[length(e[["Wijs_gauss_sym_cpp"]]) + 
        1]] <- list(Mu = Mu, sigma = sigma)
    .Call("_hetGP_Wijs_gauss_sym_cpp", PACKAGE = "hetGP", Mu, 
        sigma)
}
