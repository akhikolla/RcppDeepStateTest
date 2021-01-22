function (thetaTmp, mtmp, max_m_tmp, ttmp, KnotI, KnotM) 
{
    e <- get("data.env", .GlobalEnv)
    e[["truePos"]][[length(e[["truePos"]]) + 1]] <- list(thetaTmp = thetaTmp, 
        mtmp = mtmp, max_m_tmp = max_m_tmp, ttmp = ttmp, KnotI = KnotI, 
        KnotM = KnotM)
    .Call("_intcensROC_truePos", PACKAGE = "intcensROC", thetaTmp, 
        mtmp, max_m_tmp, ttmp, KnotI, KnotM)
}
