function (urls, component) 
{
    e <- get("data.env", .GlobalEnv)
    e[["rm_component_"]][[length(e[["rm_component_"]]) + 1]] <- list(urls = urls, 
        component = component)
    .Call("_urltools_rm_component_", urls, component)
}
