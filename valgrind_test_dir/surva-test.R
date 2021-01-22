function (thetaTmp, m, m2, t, KnotI, KnotM) 
{
    e <- get("data.env", .GlobalEnv)
    e[["surva"]][[length(e[["surva"]]) + 1]] <- list(thetaTmp = thetaTmp, 
        m = m, m2 = m2, t = t, KnotI = KnotI, KnotM = KnotM)
    .Call("_cenROC_surva", PACKAGE = "cenROC", thetaTmp, m, m2, 
        t, KnotI, KnotM)
}
