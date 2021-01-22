function (phi1, phi0, J, negpred) 
{
    e <- get("data.env", .GlobalEnv)
    e[["powerdmat3"]][[length(e[["powerdmat3"]]) + 1]] <- list(phi1 = phi1, 
        phi0 = phi0, J = J, negpred = negpred)
    .Call("_icensmis_powerdmat3", PACKAGE = "icensmis", phi1, 
        phi0, J, negpred)
}
