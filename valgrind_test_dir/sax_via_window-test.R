function (ts, w_size, paa_size, a_size, nr_strategy, n_threshold) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sax_via_window"]][[length(e[["sax_via_window"]]) + 1]] <- list(ts = ts, 
        w_size = w_size, paa_size = paa_size, a_size = a_size, 
        nr_strategy = nr_strategy, n_threshold = n_threshold)
    .Call("_jmotif_sax_via_window", PACKAGE = "jmotif", ts, w_size, 
        paa_size, a_size, nr_strategy, n_threshold)
}
