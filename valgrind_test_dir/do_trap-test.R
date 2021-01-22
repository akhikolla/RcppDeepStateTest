function (x, y, type) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_trap"]][[length(e[["do_trap"]]) + 1]] <- list(x = x, 
        y = y, type = type)
    .Call("_oce_do_trap", x, y, type)
}
