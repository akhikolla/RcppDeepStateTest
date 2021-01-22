function (x, a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["GoFBHK"]][[length(e[["GoFBHK"]]) + 1]] <- list(x = x, 
        a = a)
    .Call("_EWGoF_GoFBHK", x, a)
}
