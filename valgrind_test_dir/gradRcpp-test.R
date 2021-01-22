function (par, T, ab, wt, aj1T, bj1T, cj1T, nummet, itmp, D, 
    base) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gradRcpp"]][[length(e[["gradRcpp"]]) + 1]] <- list(par = par, 
        T = T, ab = ab, wt = wt, aj1T = aj1T, bj1T = bj1T, cj1T = cj1T, 
        nummet = nummet, itmp = itmp, D = D, base = base)
    .Call("_equateMultiple_gradRcpp", par, T, ab, wt, aj1T, bj1T, 
        cj1T, nummet, itmp, D, base)
}
