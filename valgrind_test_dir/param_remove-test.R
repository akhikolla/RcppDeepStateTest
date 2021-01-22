function (urls, keys) 
{
    e <- get("data.env", .GlobalEnv)
    e[["param_remove"]][[length(e[["param_remove"]]) + 1]] <- list(urls = urls, 
        keys = keys)
    .Call("_urltools_param_remove", urls, keys)
}
