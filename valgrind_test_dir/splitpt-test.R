function (Dmat, x, parm) 
{
    e <- get("data.env", .GlobalEnv)
    e[["splitpt"]][[length(e[["splitpt"]]) + 1]] <- list(Dmat = Dmat, 
        x = x, parm = parm)
    .Call("_icRSF_splitpt", PACKAGE = "icRSF", Dmat, x, parm)
}
