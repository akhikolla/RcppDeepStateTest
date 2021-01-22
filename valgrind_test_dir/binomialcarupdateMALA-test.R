function (Wtriplet, Wbegfin, Wtripletsum, nsites, phi, tau2, 
    y, failures, trials, phi_tune, rho, offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["binomialcarupdateMALA"]][[length(e[["binomialcarupdateMALA"]]) + 
        1]] <- list(Wtriplet = Wtriplet, Wbegfin = Wbegfin, Wtripletsum = Wtripletsum, 
        nsites = nsites, phi = phi, tau2 = tau2, y = y, failures = failures, 
        trials = trials, phi_tune = phi_tune, rho = rho, offset = offset)
    .Call("_CARBayes_binomialcarupdateMALA", Wtriplet, Wbegfin, 
        Wtripletsum, nsites, phi, tau2, y, failures, trials, 
        phi_tune, rho, offset)
}
