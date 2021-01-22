function (ts, threshold = 0.01) 
{
    e <- get("data.env", .GlobalEnv)
    e[["znorm"]][[length(e[["znorm"]]) + 1]] <- list(ts = ts, 
        threshold = threshold)
    .Call("_jmotif_znorm", PACKAGE = "jmotif", ts, threshold)
}
