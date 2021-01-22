function (t, n, m) 
{
    e <- get("data.env", .GlobalEnv)
    e[["GoFNS"]][[length(e[["GoFNS"]]) + 1]] <- list(t = t, n = n, 
        m = m)
    .Call("_EWGoF_GoFNS", t, n, m)
}
