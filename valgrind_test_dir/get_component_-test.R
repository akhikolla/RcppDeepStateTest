function (urls, component) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_component_"]][[length(e[["get_component_"]]) + 1]] <- list(urls = urls, 
        component = component)
    .Call("_urltools_get_component_", urls, component)
}
