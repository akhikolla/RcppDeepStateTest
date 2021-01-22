function (mat, k, windowsize, maxsd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["threshold_adaptive"]][[length(e[["threshold_adaptive"]]) + 
        1]] <- list(mat = mat, k = k, windowsize = windowsize, 
        maxsd = maxsd)
    .Call("_imagerExtra_threshold_adaptive", mat, k, windowsize, 
        maxsd)
}
