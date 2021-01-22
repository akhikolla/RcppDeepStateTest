function (urls) 
{
    e <- get("data.env", .GlobalEnv)
    e[["url_decode"]][[length(e[["url_decode"]]) + 1]] <- list(urls = urls)
    .Call("_urltools_url_decode", urls)
}
