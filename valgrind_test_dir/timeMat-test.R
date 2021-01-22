function (nsub, J, time, utime, Xmat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["timeMat"]][[length(e[["timeMat"]]) + 1]] <- list(nsub = nsub, 
        J = J, time = time, utime = utime, Xmat = Xmat)
    .Call("_icensmis_timeMat", PACKAGE = "icensmis", nsub, J, 
        time, utime, Xmat)
}
