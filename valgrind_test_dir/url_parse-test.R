function (urls) 
{
    e <- get("data.env", .GlobalEnv)
    e[["url_parse"]][[length(e[["url_parse"]]) + 1]] <- list(urls = urls)
    .Call("_urltools_url_parse", urls)
}
