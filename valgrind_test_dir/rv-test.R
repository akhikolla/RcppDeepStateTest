function (a, b, na, period, tmpa, tmpb, tmpna) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rv"]][[length(e[["rv"]]) + 1]] <- list(a = a, b = b, 
        na = na, period = period, tmpa = tmpa, tmpb = tmpb, tmpna = tmpna)
    .Call("_highfrequency_rv", a, b, na, period, tmpa, tmpb, 
        tmpna)
}
