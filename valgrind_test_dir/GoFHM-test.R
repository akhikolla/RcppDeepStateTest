function (x, a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["GoFHM"]][[length(e[["GoFHM"]]) + 1]] <- list(x = x, a = a)
    .Call("_EWGoF_GoFHM", x, a)
}
