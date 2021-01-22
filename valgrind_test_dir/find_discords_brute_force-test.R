function (ts, w_size, discords_num) 
{
    e <- get("data.env", .GlobalEnv)
    e[["find_discords_brute_force"]][[length(e[["find_discords_brute_force"]]) + 
        1]] <- list(ts = ts, w_size = w_size, discords_num = discords_num)
    .Call("_jmotif_find_discords_brute_force", PACKAGE = "jmotif", 
        ts, w_size, discords_num)
}
