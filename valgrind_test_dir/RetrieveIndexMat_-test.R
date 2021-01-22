function (indices) 
{
    e <- get("data.env", .GlobalEnv)
    e[["RetrieveIndexMat_"]][[length(e[["RetrieveIndexMat_"]]) + 
        1]] <- list(indices = indices)
    .Call("_icosa_RetrieveIndexMat_", indices)
}
