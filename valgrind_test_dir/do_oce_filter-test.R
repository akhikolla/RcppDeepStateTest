function (x, a, b) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_oce_filter"]][[length(e[["do_oce_filter"]]) + 1]] <- list(x = x, 
        a = a, b = b)
    .Call("_oce_do_oce_filter", x, a, b)
}
