function (im, cx, cy, wx, wy, boundary_conditions = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["extract_patches"]][[length(e[["extract_patches"]]) + 
        1]] <- list(im = im, cx = cx, cy = cy, wx = wx, wy = wy, 
        boundary_conditions = boundary_conditions)
    .Call("_imager_extract_patches", im, cx, cy, wx, wy, boundary_conditions)
}
