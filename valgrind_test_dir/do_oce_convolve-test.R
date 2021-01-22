function (x, f, end) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_oce_convolve"]][[length(e[["do_oce_convolve"]]) + 
        1]] <- list(x = x, f = f, end = end)
    .Call("_oce_do_oce_convolve", x, f, end)
}
