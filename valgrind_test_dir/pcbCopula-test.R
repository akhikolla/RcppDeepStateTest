function (u, x, m) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pcbCopula"]][[length(e[["pcbCopula"]]) + 1]] <- list(u = u, 
        x = x, m = m)
    .Call("_cort_pcbCopula", u, x, m)
}
