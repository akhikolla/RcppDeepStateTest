function (x, a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["GoFBH"]][[length(e[["GoFBH"]]) + 1]] <- list(x = x, a = a)
    .Call("_EWGoF_GoFBH", x, a)
}
