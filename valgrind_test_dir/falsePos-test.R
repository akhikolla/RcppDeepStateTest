function (thetaTmp, m, max_m, t, KnotI, KnotM) 
{
    e <- get("data.env", .GlobalEnv)
    e[["falsePos"]][[length(e[["falsePos"]]) + 1]] <- list(thetaTmp = thetaTmp, 
        m = m, max_m = max_m, t = t, KnotI = KnotI, KnotM = KnotM)
    .Call("_intcensROC_falsePos", PACKAGE = "intcensROC", thetaTmp, 
        m, max_m, t, KnotI, KnotM)
}
