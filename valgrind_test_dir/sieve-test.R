function (Utmp, Vtmp, Markertmp, Deltatmp, KnotI, KnotM, ki) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sieve"]][[length(e[["sieve"]]) + 1]] <- list(Utmp = Utmp, 
        Vtmp = Vtmp, Markertmp = Markertmp, Deltatmp = Deltatmp, 
        KnotI = KnotI, KnotM = KnotM, ki = ki)
    .Call("_intcensROC_sieve", PACKAGE = "intcensROC", Utmp, 
        Vtmp, Markertmp, Deltatmp, KnotI, KnotM, ki)
}
