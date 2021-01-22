function (x, y, freq, seed, dist, value, dist2ind, jitter) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gen_worley2d_c"]][[length(e[["gen_worley2d_c"]]) + 1]] <- list(x = x, 
        y = y, freq = freq, seed = seed, dist = dist, value = value, 
        dist2ind = dist2ind, jitter = jitter)
    .Call("_ambient_gen_worley2d_c", PACKAGE = "ambient", x, 
        y, freq, seed, dist, value, dist2ind, jitter)
}
