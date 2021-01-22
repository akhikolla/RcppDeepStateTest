function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["puny_decode"]][[length(e[["puny_decode"]]) + 1]] <- list(x = x)
    .Call("_urltools_puny_decode", x)
}
