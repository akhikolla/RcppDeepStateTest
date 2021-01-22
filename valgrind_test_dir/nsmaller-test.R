function (times, lengths, start, end, max) 
{
    e <- get("data.env", .GlobalEnv)
    e[["nsmaller"]][[length(e[["nsmaller"]]) + 1]] <- list(times = times, 
        lengths = lengths, start = start, end = end, max = max)
    .Call("_highfrequency_nsmaller", times, lengths, start, end, 
        max)
}
