function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["resize_doubleXY"]][[length(e[["resize_doubleXY"]]) + 
        1]] <- list(im = im)
    .Call("_imager_resize_doubleXY", im)
}
