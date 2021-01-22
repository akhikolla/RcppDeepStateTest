function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["HSItoRGB"]][[length(e[["HSItoRGB"]]) + 1]] <- list(im = im)
    .Call("_imager_HSItoRGB", im)
}
