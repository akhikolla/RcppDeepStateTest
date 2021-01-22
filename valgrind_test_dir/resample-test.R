function (raw, rawTime, time, stop) 
{
    e <- get("data.env", .GlobalEnv)
    e[["resample"]][[length(e[["resample"]]) + 1]] <- list(raw = raw, 
        rawTime = rawTime, time = time, stop = stop)
    .Call("_GGIR_resample", raw, rawTime, time, stop)
}
