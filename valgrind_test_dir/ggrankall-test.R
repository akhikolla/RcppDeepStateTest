function (n, m, rep) 
{
    e <- get("data.env", .GlobalEnv)
    e[["ggrankall"]][[length(e[["ggrankall"]]) + 1]] <- list(n = n, 
        m = m, rep = rep)
    .Call("_dfphase1_ggrankall", PACKAGE = "dfphase1", n, m, 
        rep)
}
