function (domains) 
{
    e <- get("data.env", .GlobalEnv)
    e[["host_extract_"]][[length(e[["host_extract_"]]) + 1]] <- list(domains = domains)
    .Call("_urltools_host_extract_", domains)
}
