function (x, a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["GoFBHC"]][[length(e[["GoFBHC"]]) + 1]] <- list(x = x, 
        a = a)
    .Call("_EWGoF_GoFBHC", x, a)
}
