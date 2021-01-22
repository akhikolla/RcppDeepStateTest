function (im, cx, cy, cz, wx, wy, wz, boundary_conditions = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["extract_patches3D"]][[length(e[["extract_patches3D"]]) + 
        1]] <- list(im = im, cx = cx, cy = cy, cz = cz, wx = wx, 
        wy = wy, wz = wz, boundary_conditions = boundary_conditions)
    .Call("_imager_extract_patches3D", im, cx, cy, cz, wx, wy, 
        wz, boundary_conditions)
}
