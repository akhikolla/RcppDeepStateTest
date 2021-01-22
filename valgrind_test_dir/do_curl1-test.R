function (u, v, x, y, geographical) 
{
    e <- get("data.env", .GlobalEnv)
    e[["do_curl1"]][[length(e[["do_curl1"]]) + 1]] <- list(u = u, 
        v = v, x = x, y = y, geographical = geographical)
    .Call("_oce_do_curl1", u, v, x, y, geographical)
}
