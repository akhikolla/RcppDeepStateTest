function (domains) 
{
    e <- get("data.env", .GlobalEnv)
    e[["tld_extract_"]][[length(e[["tld_extract_"]]) + 1]] <- list(domains = domains)
    .Call("_urltools_tld_extract_", domains)
}
