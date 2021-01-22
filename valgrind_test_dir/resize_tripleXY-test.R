function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["resize_tripleXY"]][[length(e[["resize_tripleXY"]]) + 
        1]] <- list(im = im)
    .Call("_imager_resize_tripleXY", im)
}
