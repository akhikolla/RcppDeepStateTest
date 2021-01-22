function (Tobesum, nind, nobs, ind) 
{
    e <- get("data.env", .GlobalEnv)
    e[["aggregatesum"]][[length(e[["aggregatesum"]]) + 1]] <- list(Tobesum = Tobesum, 
        nind = nind, nobs = nobs, ind = ind)
    .Call("_Rlda_aggregatesum", Tobesum, nind, nobs, ind)
}
