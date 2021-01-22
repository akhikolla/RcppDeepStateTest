function (im, delta_x = 0L, delta_y = 0L, delta_z = 0L, delta_c = 0L, 
    boundary_conditions = 0L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["imshift"]][[length(e[["imshift"]]) + 1]] <- list(im = im, 
        delta_x = delta_x, delta_y = delta_y, delta_z = delta_z, 
        delta_c = delta_c, boundary_conditions = boundary_conditions)
    .Call("_imager_imshift", im, delta_x, delta_y, delta_z, delta_c, 
        boundary_conditions)
}
