function (mat) 
{
    e <- get("data.env", .GlobalEnv)
    e[["IDCT2D_toDFT"]][[length(e[["IDCT2D_toDFT"]]) + 1]] <- list(mat = mat)
    .Call("_imagerExtra_IDCT2D_toDFT", mat)
}
