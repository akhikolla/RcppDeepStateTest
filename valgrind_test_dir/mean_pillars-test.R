function (arr3d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mean_pillars"]][[length(e[["mean_pillars"]]) + 1]] <- list(arr3d = arr3d)
    .Call("_autothresholdr_mean_pillars", arr3d)
}
