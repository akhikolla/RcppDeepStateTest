function (ts, paa_num) 
{
    e <- get("data.env", .GlobalEnv)
    e[["paa"]][[length(e[["paa"]]) + 1]] <- list(ts = ts, paa_num = paa_num)
    .Call("_jmotif_paa", PACKAGE = "jmotif", ts, paa_num)
}
