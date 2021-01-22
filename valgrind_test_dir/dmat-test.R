function (id, time, result, phi1, phi0, negpred) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dmat"]][[length(e[["dmat"]]) + 1]] <- list(id = id, time = time, 
        result = result, phi1 = phi1, phi0 = phi0, negpred = negpred)
    .Call("_icensmis_dmat", PACKAGE = "icensmis", id, time, result, 
        phi1, phi0, negpred)
}
