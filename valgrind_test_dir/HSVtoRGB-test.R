function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["HSVtoRGB"]][[length(e[["HSVtoRGB"]]) + 1]] <- list(im = im)
    .Call("_imager_HSVtoRGB", im)
}
