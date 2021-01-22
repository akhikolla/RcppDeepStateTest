function (x_breaks, y_breaks, grid, x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["bilinear"]][[length(e[["bilinear"]]) + 1]] <- list(x_breaks = x_breaks, 
        y_breaks = y_breaks, grid = grid, x = x, y = y)
    .Call("_particles_bilinear", PACKAGE = "particles", x_breaks, 
        y_breaks, grid, x, y)
}
