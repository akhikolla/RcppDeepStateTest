function (f) 
{
    e <- get("data.env", .GlobalEnv)
    e[["pointLayerColorOrder_"]][[length(e[["pointLayerColorOrder_"]]) + 
        1]] <- list(f = f)
    .Call("_icosa_pointLayerColorOrder_", f)
}
