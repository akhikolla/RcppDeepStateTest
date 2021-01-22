function (x, indices, redBand, blueBand, greenBand, nirBand, 
    redEdge1Band, redEdge2Band, redEdge3Band, swir1Band, swir2Band, 
    swir3Band, maskLayer, maskValue, L, s, G, C1, C2, Levi, swir2ccc, 
    swir2cdiff, sf) 
{
    e <- get("data.env", .GlobalEnv)
    e[["spectralIndicesCpp"]][[length(e[["spectralIndicesCpp"]]) + 
        1]] <- list(x = x, indices = indices, redBand = redBand, 
        blueBand = blueBand, greenBand = greenBand, nirBand = nirBand, 
        redEdge1Band = redEdge1Band, redEdge2Band = redEdge2Band, 
        redEdge3Band = redEdge3Band, swir1Band = swir1Band, swir2Band = swir2Band, 
        swir3Band = swir3Band, maskLayer = maskLayer, maskValue = maskValue, 
        L = L, s = s, G = G, C1 = C1, C2 = C2, Levi = Levi, swir2ccc = swir2ccc, 
        swir2cdiff = swir2cdiff, sf = sf)
    .Call("_RStoolbox_spectralIndicesCpp", PACKAGE = "RStoolbox", 
        x, indices, redBand, blueBand, greenBand, nirBand, redEdge1Band, 
        redEdge2Band, redEdge3Band, swir1Band, swir2Band, swir3Band, 
        maskLayer, maskValue, L, s, G, C1, C2, Levi, swir2ccc, 
        swir2cdiff, sf)
}
