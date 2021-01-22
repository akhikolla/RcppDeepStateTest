function (h, O, A, B, TT, K, pMax, qMax, data, backCast, LB, 
    UB, llRM, lls) 
{
    e <- get("data.env", .GlobalEnv)
    e[["heavy_likelihoodR_"]][[length(e[["heavy_likelihoodR_"]]) + 
        1]] <- list(h = h, O = O, A = A, B = B, TT = TT, K = K, 
        pMax = pMax, qMax = qMax, data = data, backCast = backCast, 
        LB = LB, UB = UB, llRM = llRM, lls = lls)
    .Call("_highfrequency_heavy_likelihoodR_", h, O, A, B, TT, 
        K, pMax, qMax, data, backCast, LB, UB, llRM, lls)
}
