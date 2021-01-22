function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["puny_encode"]][[length(e[["puny_encode"]]) + 1]] <- list(x = x)
    .Call("_urltools_puny_encode", x)
}
