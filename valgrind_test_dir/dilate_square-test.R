function (im, size) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dilate_square"]][[length(e[["dilate_square"]]) + 1]] <- list(im = im, 
        size = size)
    .Call("_imager_dilate_square", im, size)
}
