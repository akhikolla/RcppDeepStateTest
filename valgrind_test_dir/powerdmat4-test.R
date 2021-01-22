function (phi1, phi0, J, negpred, pmiss, censor) 
{
    e <- get("data.env", .GlobalEnv)
    e[["powerdmat4"]][[length(e[["powerdmat4"]]) + 1]] <- list(phi1 = phi1, 
        phi0 = phi0, J = J, negpred = negpred, pmiss = pmiss, 
        censor = censor)
    .Call("_icensmis_powerdmat4", PACKAGE = "icensmis", phi1, 
        phi0, J, negpred, pmiss, censor)
}
