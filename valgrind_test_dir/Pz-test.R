function (mu, alpha, zeta1, zeta2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["Pz"]][[length(e[["Pz"]]) + 1]] <- list(mu = mu, alpha = alpha, 
        zeta1 = zeta1, zeta2 = zeta2)
    .Call("_RJafroc_Pz", PACKAGE = "RJafroc", mu, alpha, zeta1, 
        zeta2)
}
