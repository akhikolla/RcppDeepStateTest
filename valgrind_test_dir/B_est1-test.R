function (time, status, stime, stime1, G, X, tau_bet, epstheta, 
    Edot, pdim) 
{
    e <- get("data.env", .GlobalEnv)
    e[["B_est1"]][[length(e[["B_est1"]]) + 1]] <- list(time = time, 
        status = status, stime = stime, stime1 = stime1, G = G, 
        X = X, tau_bet = tau_bet, epstheta = epstheta, Edot = Edot, 
        pdim = pdim)
    .Call("_ivtools_B_est1", time, status, stime, stime1, G, 
        X, tau_bet, epstheta, Edot, pdim)
}
