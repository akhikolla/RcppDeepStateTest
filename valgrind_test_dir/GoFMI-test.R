function (x, a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["GoFMI"]][[length(e[["GoFMI"]]) + 1]] <- list(x = x, a = a)
    .Call("_EWGoF_GoFMI", x, a)
}
