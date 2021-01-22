function (x, y, xout, window, L) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_runlm"]][[length(e[["do_runlm"]]) + 1]] <- list(x = x, 
        y = y, xout = xout, window = window, L = L)
    .Call("_oce_do_runlm", x, y, xout, window, L)
}
