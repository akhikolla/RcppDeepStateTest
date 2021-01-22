function (im, thresvals) 
{
    e <- get("data.env", .GlobalEnv)
    e[["threshold_multilevel"]][[length(e[["threshold_multilevel"]]) + 
        1]] <- list(im = im, thresvals = thresvals)
    .Call("_imagerExtra_threshold_multilevel", im, thresvals)
}
