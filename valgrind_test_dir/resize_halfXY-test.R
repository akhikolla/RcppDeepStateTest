function (im) 
{
    e <- get("data.env", .GlobalEnv)
    e[["resize_halfXY"]][[length(e[["resize_halfXY"]]) + 1]] <- list(im = im)
    .Call("_imager_resize_halfXY", im)
}
