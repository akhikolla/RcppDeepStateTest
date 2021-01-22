function (a, ap, b, at, atp, bt, na, nap, nb, period) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pcovcc"]][[length(e[["pcovcc"]]) + 1]] <- list(a = a, 
        ap = ap, b = b, at = at, atp = atp, bt = bt, na = na, 
        nap = nap, nb = nb, period = period)
    .Call("_highfrequency_pcovcc", a, ap, b, at, atp, bt, na, 
        nap, nb, period)
}
