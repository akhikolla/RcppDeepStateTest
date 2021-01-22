function (ts, paa_size, a_size, n_threshold) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sax_by_chunking"]][[length(e[["sax_by_chunking"]]) + 
        1]] <- list(ts = ts, paa_size = paa_size, a_size = a_size, 
        n_threshold = n_threshold)
    .Call("_jmotif_sax_by_chunking", PACKAGE = "jmotif", ts, 
        paa_size, a_size, n_threshold)
}
