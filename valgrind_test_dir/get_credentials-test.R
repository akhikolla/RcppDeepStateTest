function (urls) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_credentials"]][[length(e[["get_credentials"]]) + 
        1]] <- list(urls = urls)
    .Call("_urltools_get_credentials", urls)
}
