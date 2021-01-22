function (im, size) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mclosing_square"]][[length(e[["mclosing_square"]]) + 
        1]] <- list(im = im, size = size)
    .Call("_imager_mclosing_square", im, size)
}
