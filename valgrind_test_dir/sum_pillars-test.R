function (arr3d) 
{
    e <- get("data.env", .GlobalEnv)
    e[["sum_pillars"]][[length(e[["sum_pillars"]]) + 1]] <- list(arr3d = arr3d)
    .Call("_autothresholdr_sum_pillars", arr3d)
}
