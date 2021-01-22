function (urls) 
{
    e <- get("data.env", .GlobalEnv)
    e[["strip_credentials"]][[length(e[["strip_credentials"]]) + 
        1]] <- list(urls = urls)
    .Call("_urltools_strip_credentials", urls)
}
