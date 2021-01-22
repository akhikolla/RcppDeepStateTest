function (rate, days, times) 
{
    e <- get("data.env", .GlobalEnv)
    e[["calcTsplitC"]][[length(e[["calcTsplitC"]]) + 1]] <- list(rate = rate, 
        days = days, times = times)
    .Call("_GenEst_calcTsplitC", rate, days, times)
}
