function (counts, weartime, thresh) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sedbreaks_flags"]][[length(e[["sedbreaks_flags"]]) + 
        1]] <- list(counts = counts, weartime = weartime, thresh = thresh)
    .Call("_accelerometry_sedbreaks_flags", counts, weartime, 
        thresh)
}
