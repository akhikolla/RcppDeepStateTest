function (urls, component, new_value) 
{
    e <- get("data.env", .GlobalEnv)
    e[["set_component_"]][[length(e[["set_component_"]]) + 1]] <- list(urls = urls, 
        component = component, new_value = new_value)
    .Call("_urltools_set_component_", urls, component, new_value)
}
