function (counts, weartime, thresh) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sedbreaks"]][[length(e[["sedbreaks"]]) + 1]] <- list(counts = counts, 
        weartime = weartime, thresh = thresh)
    .Call("_accelerometry_sedbreaks", counts, weartime, thresh)
}
