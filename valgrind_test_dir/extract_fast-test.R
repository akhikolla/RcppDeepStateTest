function (im, fun, cx, cy, wx, wy) 
{
    e <- get("data.env", .GlobalEnv)
    e[["extract_fast"]][[length(e[["extract_fast"]]) + 1]] <- list(im = im, 
        fun = fun, cx = cx, cy = cy, wx = wx, wy = wy)
    .Call("_imager_extract_fast", im, fun, cx, cy, wx, wy)
}
