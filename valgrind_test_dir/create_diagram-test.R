function (sites) 
{
    e <- get("data.env", .GlobalEnv)
    e[["create_diagram"]][[length(e[["create_diagram"]]) + 1]] <- list(sites = sites)
    .Call("_transport_create_diagram", sites)
}
