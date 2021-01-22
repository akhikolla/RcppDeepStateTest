function (im, size) 
{
    e <- get("data.env", .GlobalEnv)
    e[["erode_square"]][[length(e[["erode_square"]]) + 1]] <- list(im = im, 
        size = size)
    .Call("_imager_erode_square", im, size)
}
