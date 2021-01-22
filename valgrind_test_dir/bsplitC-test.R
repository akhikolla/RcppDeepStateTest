function (Dmat, Xmat, parm) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bsplitC"]][[length(e[["bsplitC"]]) + 1]] <- list(Dmat = Dmat, 
        Xmat = Xmat, parm = parm)
    .Call("_icRSF_bsplitC", PACKAGE = "icRSF", Dmat, Xmat, parm)
}
