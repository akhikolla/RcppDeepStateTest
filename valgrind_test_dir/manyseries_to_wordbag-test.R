function (data, w_size, paa_size, a_size, nr_strategy, n_threshold) 
{
    e <- get("data.env", .GlobalEnv)
    e[["manyseries_to_wordbag"]][[length(e[["manyseries_to_wordbag"]]) + 
        1]] <- list(data = data, w_size = w_size, paa_size = paa_size, 
        a_size = a_size, nr_strategy = nr_strategy, n_threshold = n_threshold)
    .Call("_jmotif_manyseries_to_wordbag", PACKAGE = "jmotif", 
        data, w_size, paa_size, a_size, nr_strategy, n_threshold)
}
