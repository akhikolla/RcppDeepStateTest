function (a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["angle_diff"]][[length(e[["angle_diff"]]) + 1]] <- list(a = a, 
        b = b)
    .Call("_particles_angle_diff", PACKAGE = "particles", a, 
        b)
}
