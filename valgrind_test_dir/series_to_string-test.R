function (ts, a_size) 
{
    e <- get("data.env", .GlobalEnv)
    e[["series_to_string"]][[length(e[["series_to_string"]]) + 
        1]] <- list(ts = ts, a_size = a_size)
    .Call("_jmotif_series_to_string", PACKAGE = "jmotif", ts, 
        a_size)
}
