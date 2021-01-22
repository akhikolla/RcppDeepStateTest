function (pos, strength, theta, min_dist, max_dist, alpha) 
{
    e <- get("data.env", .GlobalEnv)
    e[["nbody"]][[length(e[["nbody"]]) + 1]] <- list(pos = pos, 
        strength = strength, theta = theta, min_dist = min_dist, 
        max_dist = max_dist, alpha = alpha)
    .Call("_particles_nbody", PACKAGE = "particles", pos, strength, 
        theta, min_dist, max_dist, alpha)
}
