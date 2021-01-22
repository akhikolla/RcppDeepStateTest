function (x, a, a1) 
{
    e <- get("data.env", .GlobalEnv)
    e[["GoFHe"]][[length(e[["GoFHe"]]) + 1]] <- list(x = x, a = a, 
        a1 = a1)
    .Call("_EWGoF_GoFHe", x, a, a1)
}
