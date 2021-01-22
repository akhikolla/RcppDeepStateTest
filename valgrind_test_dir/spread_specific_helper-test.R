function (interval_lengths, interval_pops, m) 
{
    e <- get("data.env", .GlobalEnv)
    e[["spread_specific_helper"]][[length(e[["spread_specific_helper"]]) + 
        1]] <- list(interval_lengths = interval_lengths, interval_pops = interval_pops, 
        m = m)
    .Call("_nandb_spread_specific_helper", interval_lengths, 
        interval_pops, m)
}
