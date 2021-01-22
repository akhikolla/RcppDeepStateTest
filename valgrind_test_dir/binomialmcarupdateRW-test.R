function (Wtriplet, Wbegfin, nsites, nvar, phi, Y, failures, 
    phioffset, denoffset, Sigmainv, rho, phi_tune) 
{
    e <- get("data.env", .GlobalEnv)
    e[["binomialmcarupdateRW"]][[length(e[["binomialmcarupdateRW"]]) + 
        1]] <- list(Wtriplet = Wtriplet, Wbegfin = Wbegfin, nsites = nsites, 
        nvar = nvar, phi = phi, Y = Y, failures = failures, phioffset = phioffset, 
        denoffset = denoffset, Sigmainv = Sigmainv, rho = rho, 
        phi_tune = phi_tune)
    .Call("_CARBayes_binomialmcarupdateRW", Wtriplet, Wbegfin, 
        nsites, nvar, phi, Y, failures, phioffset, denoffset, 
        Sigmainv, rho, phi_tune)
}
