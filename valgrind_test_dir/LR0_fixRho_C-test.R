function (LamdasR, muR, w1R, w2R, nminuspx) 
{
    e <- get("data.env", .GlobalEnv)
    e[["LR0_fixRho_C"]][[length(e[["LR0_fixRho_C"]]) + 1]] <- list(LamdasR = LamdasR, 
        muR = muR, w1R = w1R, w2R = w2R, nminuspx = nminuspx)
    .Call("_CKLRT_LR0_fixRho_C", PACKAGE = "CKLRT", LamdasR, 
        muR, w1R, w2R, nminuspx)
}
