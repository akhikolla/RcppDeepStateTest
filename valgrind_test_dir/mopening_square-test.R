function (im, size) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mopening_square"]][[length(e[["mopening_square"]]) + 
        1]] <- list(im = im, size = size)
    .Call("_imager_mopening_square", im, size)
}
