function (x, n, k = 1, m = 10L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["roll_sd_filter"]][[length(e[["roll_sd_filter"]]) + 1]] <- list(x = x, 
        n = n, k = k, m = m)
    .Call("_QuantTools_roll_sd_filter", x, n, k, m)
}
