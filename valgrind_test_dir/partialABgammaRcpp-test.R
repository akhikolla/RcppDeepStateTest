function (par, T, ab, wt, aj1T, bj1T, cj1T, nummet, itmp, D, 
    base, nb, posnomi) 
{
    e <- get("data.env", .GlobalEnv)
    e[["partialABgammaRcpp"]][[length(e[["partialABgammaRcpp"]]) + 
        1]] <- list(par = par, T = T, ab = ab, wt = wt, aj1T = aj1T, 
        bj1T = bj1T, cj1T = cj1T, nummet = nummet, itmp = itmp, 
        D = D, base = base, nb = nb, posnomi = posnomi)
    .Call("_equateMultiple_partialABgammaRcpp", par, T, ab, wt, 
        aj1T, bj1T, cj1T, nummet, itmp, D, base, nb, posnomi)
}
