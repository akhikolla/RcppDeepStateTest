function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["YCbCrtoRGB"]][[length(e[["YCbCrtoRGB"]]) + 1]] <- list(im = im)
    .Call("_imager_YCbCrtoRGB", im)
}
