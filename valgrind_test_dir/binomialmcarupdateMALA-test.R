function (Wtriplet, Wbegfin, nsites, nvar, phi, Y, failures, 
    trials, phioffset, denoffset, Sigmainv, rho, phi_tune) 
{
    e <- get("data.env", .GlobalEnv)
    e[["binomialmcarupdateMALA"]][[length(e[["binomialmcarupdateMALA"]]) + 
        1]] <- list(Wtriplet = Wtriplet, Wbegfin = Wbegfin, nsites = nsites, 
        nvar = nvar, phi = phi, Y = Y, failures = failures, trials = trials, 
        phioffset = phioffset, denoffset = denoffset, Sigmainv = Sigmainv, 
        rho = rho, phi_tune = phi_tune)
    .Call("_CARBayes_binomialmcarupdateMALA", Wtriplet, Wbegfin, 
        nsites, nvar, phi, Y, failures, trials, phioffset, denoffset, 
        Sigmainv, rho, phi_tune)
}
