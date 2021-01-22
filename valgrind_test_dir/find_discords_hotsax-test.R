function (ts, w_size, paa_size, a_size, n_threshold, discords_num) 
{
    e <- get("data.env", .GlobalEnv)
    e[["find_discords_hotsax"]][[length(e[["find_discords_hotsax"]]) + 
        1]] <- list(ts = ts, w_size = w_size, paa_size = paa_size, 
        a_size = a_size, n_threshold = n_threshold, discords_num = discords_num)
    .Call("_jmotif_find_discords_hotsax", PACKAGE = "jmotif", 
        ts, w_size, paa_size, a_size, n_threshold, discords_num)
}
