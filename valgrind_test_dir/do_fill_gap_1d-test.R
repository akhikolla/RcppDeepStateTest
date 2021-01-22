function (x, rule) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_fill_gap_1d"]][[length(e[["do_fill_gap_1d"]]) + 1]] <- list(x = x, 
        rule = rule)
    .Call("_oce_do_fill_gap_1d", x, rule)
}
