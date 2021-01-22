function (Mu1, Mu2, sigma) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Wijs_mat32_cpp"]][[length(e[["Wijs_mat32_cpp"]]) + 1]] <- list(Mu1 = Mu1, 
        Mu2 = Mu2, sigma = sigma)
    .Call("_hetGP_Wijs_mat32_cpp", PACKAGE = "hetGP", Mu1, Mu2, 
        sigma)
}
