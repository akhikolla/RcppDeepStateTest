function (as) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cleanAngles"]][[length(e[["cleanAngles"]]) + 1]] <- list(as = as)
    .Call("_mousetrap_cleanAngles", as)
}
