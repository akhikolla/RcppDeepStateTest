function (mat, h = 0, s = 0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_M_HSV2RGB"]][[length(e[["cpp_M_HSV2RGB"]]) + 1]] <- list(mat = mat, 
        h = h, s = s)
    .Call("_IFC_cpp_M_HSV2RGB", mat, h, s)
}
