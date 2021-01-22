function (indices) 
{
    e <- get("data.env", .GlobalEnv)
    e[["matrixRowInds"]][[length(e[["matrixRowInds"]]) + 1]] <- list(indices = indices)
    .Call("_openxlsx_matrixRowInds", indices)
}
