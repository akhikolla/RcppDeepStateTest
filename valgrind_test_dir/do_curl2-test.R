function (u, v, x, y, geographical) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_curl2"]][[length(e[["do_curl2"]]) + 1]] <- list(u = u, 
        v = v, x = x, y = y, geographical = geographical)
    .Call("_oce_do_curl2", u, v, x, y, geographical)
}
