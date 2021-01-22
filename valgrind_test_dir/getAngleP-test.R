function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["getAngleP"]][[length(e[["getAngleP"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_mousetrap_getAngleP", x, y)
}
