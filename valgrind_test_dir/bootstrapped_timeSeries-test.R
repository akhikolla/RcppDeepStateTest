function (cpts, x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bootstrapped_timeSeries"]][[length(e[["bootstrapped_timeSeries"]]) + 
        1]] <- list(cpts = cpts, x = x)
    .Call("_mosum_bootstrapped_timeSeries", cpts, x)
}
