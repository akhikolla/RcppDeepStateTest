function (urls) 
{
    e <- get("data.env", .GlobalEnv)
    e[["url_encode"]][[length(e[["url_encode"]]) + 1]] <- list(urls = urls)
    .Call("_urltools_url_encode", urls)
}
