function (series, w_size, paa_size, a_size, nr_strategy, n_threshold, 
    discords_num) 
{
    e <- get("data.env", .GlobalEnv)
    e[["find_discords_rra"]][[length(e[["find_discords_rra"]]) + 
        1]] <- list(series = series, w_size = w_size, paa_size = paa_size, 
        a_size = a_size, nr_strategy = nr_strategy, n_threshold = n_threshold, 
        discords_num = discords_num)
    .Call("_jmotif_find_discords_rra", PACKAGE = "jmotif", series, 
        w_size, paa_size, a_size, nr_strategy, n_threshold, discords_num)
}
