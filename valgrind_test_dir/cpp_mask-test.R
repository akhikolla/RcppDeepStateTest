function (A, B, mask) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_mask"]][[length(e[["cpp_mask"]]) + 1]] <- list(A = A, 
        B = B, mask = mask)
    .Call("_IFC_cpp_mask", A, B, mask)
}
