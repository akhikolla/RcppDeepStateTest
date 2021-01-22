function (x, xlim, extra) 
{
    e <- get("data.env", .GlobalEnv)
    e[["trim_ts"]][[length(e[["trim_ts"]]) + 1]] <- list(x = x, 
        xlim = xlim, extra = extra)
    .Call("_oce_trim_ts", x, xlim, extra)
}
