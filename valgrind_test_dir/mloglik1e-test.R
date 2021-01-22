function (jtms, TT, nuvs, gcoef, InuT) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mloglik1e"]][[length(e[["mloglik1e"]]) + 1]] <- list(jtms = jtms, 
        TT = TT, nuvs = nuvs, gcoef = gcoef, InuT = InuT)
    .Call("_IHSEP_mloglik1e", PACKAGE = "IHSEP", jtms, TT, nuvs, 
        gcoef, InuT)
}
