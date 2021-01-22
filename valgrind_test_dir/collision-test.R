function (pos, vel, radii, strength) 
{
    e <- get("data.env", .GlobalEnv)
    e[["collision"]][[length(e[["collision"]]) + 1]] <- list(pos = pos, 
        vel = vel, radii = radii, strength = strength)
    .Call("_particles_collision", PACKAGE = "particles", pos, 
        vel, radii, strength)
}
