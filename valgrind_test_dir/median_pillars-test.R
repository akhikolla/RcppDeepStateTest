function (arr3d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["median_pillars"]][[length(e[["median_pillars"]]) + 1]] <- list(arr3d = arr3d)
    .Call("_autothresholdr_median_pillars", arr3d)
}
