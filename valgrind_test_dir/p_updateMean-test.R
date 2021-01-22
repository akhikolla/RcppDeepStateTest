function (Xm, U1m, U2m, I, Mv) 
{
    e <- get("data.env", .GlobalEnv)
    e[["p_updateMean"]][[length(e[["p_updateMean"]]) + 1]] <- list(Xm = Xm, 
        U1m = U1m, U2m = U2m, I = I, Mv = Mv)
    .Call("_CMF_p_updateMean", Xm, U1m, U2m, I, Mv)
}
