function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["YUVtoRGB"]][[length(e[["YUVtoRGB"]]) + 1]] <- list(im = im)
    .Call("_imager_YUVtoRGB", im)
}
