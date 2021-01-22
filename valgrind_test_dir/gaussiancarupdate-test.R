function (Wtriplet, Wbegfin, Wtripletsum, nsites, phi, tau2, 
    rho, nu2, offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gaussiancarupdate"]][[length(e[["gaussiancarupdate"]]) + 
        1]] <- list(Wtriplet = Wtriplet, Wbegfin = Wbegfin, Wtripletsum = Wtripletsum, 
        nsites = nsites, phi = phi, tau2 = tau2, rho = rho, nu2 = nu2, 
        offset = offset)
    .Call("_CARBayes_gaussiancarupdate", Wtriplet, Wbegfin, Wtripletsum, 
        nsites, phi, tau2, rho, nu2, offset)
}
