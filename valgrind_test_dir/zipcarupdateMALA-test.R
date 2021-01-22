function (Wtriplet, Wbegfin, Wtripletsum, nsites, phi, tau2, 
    y, phi_tune, rho, offset, poiind) 
{
    e <- get("data.env", .GlobalEnv)
    e[["zipcarupdateMALA"]][[length(e[["zipcarupdateMALA"]]) + 
        1]] <- list(Wtriplet = Wtriplet, Wbegfin = Wbegfin, Wtripletsum = Wtripletsum, 
        nsites = nsites, phi = phi, tau2 = tau2, y = y, phi_tune = phi_tune, 
        rho = rho, offset = offset, poiind = poiind)
    .Call("_CARBayes_zipcarupdateMALA", Wtriplet, Wbegfin, Wtripletsum, 
        nsites, phi, tau2, y, phi_tune, rho, offset, poiind)
}
