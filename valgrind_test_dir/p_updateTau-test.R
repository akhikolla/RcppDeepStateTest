function (Xm, U1m, U2m, cov1m, cov2m, Rv, Cv, nu1v, nu2v) 
{
    e <- get("data.env", .GlobalEnv)
    e[["p_updateTau"]][[length(e[["p_updateTau"]]) + 1]] <- list(Xm = Xm, 
        U1m = U1m, U2m = U2m, cov1m = cov1m, cov2m = cov2m, Rv = Rv, 
        Cv = Cv, nu1v = nu1v, nu2v = nu2v)
    .Call("_CMF_p_updateTau", Xm, U1m, U2m, cov1m, cov2m, Rv, 
        Cv, nu1v, nu2v)
}
