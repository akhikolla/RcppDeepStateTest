function (Wtriplet, Wbegfin, Wtripletsum, n_individual, nsites, 
    phi, tau2, rho, nu2, offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gaussiancarmultilevelupdate"]][[length(e[["gaussiancarmultilevelupdate"]]) + 
        1]] <- list(Wtriplet = Wtriplet, Wbegfin = Wbegfin, Wtripletsum = Wtripletsum, 
        n_individual = n_individual, nsites = nsites, phi = phi, 
        tau2 = tau2, rho = rho, nu2 = nu2, offset = offset)
    .Call("_CARBayes_gaussiancarmultilevelupdate", Wtriplet, 
        Wbegfin, Wtripletsum, n_individual, nsites, phi, tau2, 
        rho, nu2, offset)
}
