function (min1, max1, min2, max2) 
{
    e <- get("data.env", .GlobalEnv)
    e[["overlap"]][[length(e[["overlap"]]) + 1]] <- list(min1 = min1, 
        max1 = max1, min2 = min2, max2 = max2)
    .Call("_highfrequency_overlap", min1, max1, min2, max2)
}
