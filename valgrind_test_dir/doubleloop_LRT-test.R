function (K1R, K2R, P0R, AR, U1R, wR, LamdasR, nminuspx, all_rho, 
    LR0_allRhoR) 
{
    e <- get("data.env", .GlobalEnv)
    e[["doubleloop_LRT"]][[length(e[["doubleloop_LRT"]]) + 1]] <- list(K1R = K1R, 
        K2R = K2R, P0R = P0R, AR = AR, U1R = U1R, wR = wR, LamdasR = LamdasR, 
        nminuspx = nminuspx, all_rho = all_rho, LR0_allRhoR = LR0_allRhoR)
    .Call("_CKLRT_doubleloop_LRT", PACKAGE = "CKLRT", K1R, K2R, 
        P0R, AR, U1R, wR, LamdasR, nminuspx, all_rho, LR0_allRhoR)
}
