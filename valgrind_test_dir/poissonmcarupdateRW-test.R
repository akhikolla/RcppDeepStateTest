function (Wtriplet, Wbegfin, nsites, nvar, phi, Y, phioffset, 
    denoffset, Sigmainv, rho, phi_tune) 
{
    e <- get("data.env", .GlobalEnv)
    e[["poissonmcarupdateRW"]][[length(e[["poissonmcarupdateRW"]]) + 
        1]] <- list(Wtriplet = Wtriplet, Wbegfin = Wbegfin, nsites = nsites, 
        nvar = nvar, phi = phi, Y = Y, phioffset = phioffset, 
        denoffset = denoffset, Sigmainv = Sigmainv, rho = rho, 
        phi_tune = phi_tune)
    .Call("_CARBayes_poissonmcarupdateRW", Wtriplet, Wbegfin, 
        nsites, nvar, phi, Y, phioffset, denoffset, Sigmainv, 
        rho, phi_tune)
}
