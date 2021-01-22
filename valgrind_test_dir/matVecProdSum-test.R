function (m, ext, v, group) 
{
    e <- get("data.env", .GlobalEnv)
    e[["matVecProdSum"]][[length(e[["matVecProdSum"]]) + 1]] <- list(m = m, 
        ext = ext, v = v, group = group)
    .Call("_PanelCount_matVecProdSum", PACKAGE = "PanelCount", 
        m, ext, v, group)
}
