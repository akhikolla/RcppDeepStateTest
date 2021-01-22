function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cmd"]][[length(e[["cmd"]]) + 1]] <- list(x = x, y = y)
    .Call("_MESS_cmd", x, y)
}
