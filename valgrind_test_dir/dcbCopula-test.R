function (u, x, m) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dcbCopula"]][[length(e[["dcbCopula"]]) + 1]] <- list(u = u, 
        x = x, m = m)
    .Call("_cort_dcbCopula", u, x, m)
}
