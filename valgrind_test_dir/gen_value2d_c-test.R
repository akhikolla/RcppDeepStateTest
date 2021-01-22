function (x, y, freq, seed, interp) 
{
    e <- get("data.env", .GlobalEnv)
    e[["gen_value2d_c"]][[length(e[["gen_value2d_c"]]) + 1]] <- list(x = x, 
        y = y, freq = freq, seed = seed, interp = interp)
    .Call("_ambient_gen_value2d_c", PACKAGE = "ambient", x, y, 
        freq, seed, interp)
}
