function (Wtriplet, Wbegfin, Wtripletsum, nsites, phi, tau2, 
    y, failures, phi_tune, rho, offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["binomialcarupdateRW"]][[length(e[["binomialcarupdateRW"]]) + 
        1]] <- list(Wtriplet = Wtriplet, Wbegfin = Wbegfin, Wtripletsum = Wtripletsum, 
        nsites = nsites, phi = phi, tau2 = tau2, y = y, failures = failures, 
        phi_tune = phi_tune, rho = rho, offset = offset)
    .Call("_CARBayes_binomialcarupdateRW", Wtriplet, Wbegfin, 
        Wtripletsum, nsites, phi, tau2, y, failures, phi_tune, 
        rho, offset)
}
