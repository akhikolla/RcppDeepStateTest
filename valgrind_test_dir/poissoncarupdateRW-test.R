function (Wtriplet, Wbegfin, Wtripletsum, nsites, phi, tau2, 
    y, phi_tune, rho, offset) 
{
    e <- get("data.env", .GlobalEnv)
    e[["poissoncarupdateRW"]][[length(e[["poissoncarupdateRW"]]) + 
        1]] <- list(Wtriplet = Wtriplet, Wbegfin = Wbegfin, Wtripletsum = Wtripletsum, 
        nsites = nsites, phi = phi, tau2 = tau2, y = y, phi_tune = phi_tune, 
        rho = rho, offset = offset)
    .Call("_CARBayes_poissoncarupdateRW", Wtriplet, Wbegfin, 
        Wtripletsum, nsites, phi, tau2, y, phi_tune, rho, offset)
}
