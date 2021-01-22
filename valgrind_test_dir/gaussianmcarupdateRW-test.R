function (Wtriplet, Wbegfin, nsites, nvar, phi, phioffset, denoffset, 
    Sigmainv, rho, nu2, phi_tune) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gaussianmcarupdateRW"]][[length(e[["gaussianmcarupdateRW"]]) + 
        1]] <- list(Wtriplet = Wtriplet, Wbegfin = Wbegfin, nsites = nsites, 
        nvar = nvar, phi = phi, phioffset = phioffset, denoffset = denoffset, 
        Sigmainv = Sigmainv, rho = rho, nu2 = nu2, phi_tune = phi_tune)
    .Call("_CARBayes_gaussianmcarupdateRW", Wtriplet, Wbegfin, 
        nsites, nvar, phi, phioffset, denoffset, Sigmainv, rho, 
        nu2, phi_tune)
}
