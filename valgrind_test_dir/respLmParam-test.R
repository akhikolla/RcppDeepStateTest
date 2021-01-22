function (x, y, cell) 
{
    e <- get("data.env", .GlobalEnv)
    e[["respLmParam"]][[length(e[["respLmParam"]]) + 1]] <- list(x = x, 
        y = y, cell = cell)
    .Call("_remote_respLmParam", PACKAGE = "remote", x, y, cell)
}
