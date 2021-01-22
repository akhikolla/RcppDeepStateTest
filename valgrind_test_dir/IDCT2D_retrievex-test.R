function (mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["IDCT2D_retrievex"]][[length(e[["IDCT2D_retrievex"]]) + 
        1]] <- list(mat = mat)
    .Call("_imagerExtra_IDCT2D_retrievex", mat)
}
