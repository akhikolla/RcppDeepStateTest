function (x, y, z, t, freq, seed) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gen_simplex4d_c"]][[length(e[["gen_simplex4d_c"]]) + 
        1]] <- list(x = x, y = y, z = z, t = t, freq = freq, 
        seed = seed)
    .Call("_ambient_gen_simplex4d_c", PACKAGE = "ambient", x, 
        y, z, t, freq, seed)
}
