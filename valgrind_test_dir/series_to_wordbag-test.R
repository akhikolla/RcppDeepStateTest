function (ts, w_size, paa_size, a_size, nr_strategy, n_threshold) 
{
    e <- get("data.env", .GlobalEnv)
    e[["series_to_wordbag"]][[length(e[["series_to_wordbag"]]) + 
        1]] <- list(ts = ts, w_size = w_size, paa_size = paa_size, 
        a_size = a_size, nr_strategy = nr_strategy, n_threshold = n_threshold)
    .Call("_jmotif_series_to_wordbag", PACKAGE = "jmotif", ts, 
        w_size, paa_size, a_size, nr_strategy, n_threshold)
}
