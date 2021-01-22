function (m, ext, ext2, v, group) 
{
    e <- get("data.env", .GlobalEnv)
    e[["matVecProdSumExt"]][[length(e[["matVecProdSumExt"]]) + 
        1]] <- list(m = m, ext = ext, ext2 = ext2, v = v, group = group)
    .Call("_PanelCount_matVecProdSumExt", PACKAGE = "PanelCount", 
        m, ext, ext2, v, group)
}
