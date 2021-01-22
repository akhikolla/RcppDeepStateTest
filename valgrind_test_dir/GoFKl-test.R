function (x, a) 
{
    e <- get("data.env", .GlobalEnv)
    e[["GoFKl"]][[length(e[["GoFKl"]]) + 1]] <- list(x = x, a = a)
    .Call("_EWGoF_GoFKl", x, a)
}
