function (Wtriplet, Wbegfin, Wtripletsum, nsites, phi, tau2, 
    y, phi_tune, rho, offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["poissoncarupdateMALA"]][[length(e[["poissoncarupdateMALA"]]) + 
        1]] <- list(Wtriplet = Wtriplet, Wbegfin = Wbegfin, Wtripletsum = Wtripletsum, 
        nsites = nsites, phi = phi, tau2 = tau2, y = y, phi_tune = phi_tune, 
        rho = rho, offset = offset)
    .Call("_CARBayes_poissoncarupdateMALA", Wtriplet, Wbegfin, 
        Wtripletsum, nsites, phi, tau2, y, phi_tune, rho, offset)
}
