function (fOrd) 
{
    e <- get("data.env", .GlobalEnv)
    e[["HexaFaces_"]][[length(e[["HexaFaces_"]]) + 1]] <- list(fOrd = fOrd)
    .Call("_icosa_HexaFaces_", fOrd)
}
