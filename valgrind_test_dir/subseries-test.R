function (ts, start, end) 
{
    e <- get("data.env", .GlobalEnv)
    e[["subseries"]][[length(e[["subseries"]]) + 1]] <- list(ts = ts, 
        start = start, end = end)
    .Call("_jmotif_subseries", PACKAGE = "jmotif", ts, start, 
        end)
}
