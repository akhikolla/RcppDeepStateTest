function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["HSLtoRGB"]][[length(e[["HSLtoRGB"]]) + 1]] <- list(im = im)
    .Call("_imager_HSLtoRGB", im)
}
