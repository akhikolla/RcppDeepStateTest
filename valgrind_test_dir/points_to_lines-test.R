function (line1, line2, point) 
{
    e <- get("data.env", .GlobalEnv)
    e[["points_to_lines"]][[length(e[["points_to_lines"]]) + 
        1]] <- list(line1 = line1, line2 = line2, point = point)
    .Call("_particles_points_to_lines", PACKAGE = "particles", 
        line1, line2, point)
}
