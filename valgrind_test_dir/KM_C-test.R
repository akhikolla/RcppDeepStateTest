function (time, delta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["KM_C"]][[length(e[["KM_C"]]) + 1]] <- list(time = time, 
        delta = delta)
    .Call("_KONPsurv_KM_C", PACKAGE = "KONPsurv", time, delta)
}
