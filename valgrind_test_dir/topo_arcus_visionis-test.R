function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["topo_arcus_visionis"]][[length(e[["topo_arcus_visionis"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
