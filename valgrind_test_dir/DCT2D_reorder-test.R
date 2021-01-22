function (mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["DCT2D_reorder"]][[length(e[["DCT2D_reorder"]]) + 1]] <- list(mat = mat)
    .Call("_imagerExtra_DCT2D_reorder", mat)
}
