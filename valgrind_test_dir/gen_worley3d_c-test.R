function (x, y, z, freq, seed, dist, value, dist2ind, jitter) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gen_worley3d_c"]][[length(e[["gen_worley3d_c"]]) + 1]] <- list(x = x, 
        y = y, z = z, freq = freq, seed = seed, dist = dist, 
        value = value, dist2ind = dist2ind, jitter = jitter)
    .Call("_ambient_gen_worley3d_c", PACKAGE = "ambient", x, 
        y, z, freq, seed, dist, value, dist2ind, jitter)
}
