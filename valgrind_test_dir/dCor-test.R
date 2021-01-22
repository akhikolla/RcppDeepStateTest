function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dCor"]][[length(e[["dCor"]]) + 1]] <- list(x = x, y = y)
    .Call("_MESS_dCor", x, y)
}
