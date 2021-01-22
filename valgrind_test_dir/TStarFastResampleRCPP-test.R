function (xNumeric, yNumeric, numResamples, sampleSize) 
{
    e <- get("data.env", .GlobalEnv)
    e[["TStarFastResampleRCPP"]][[length(e[["TStarFastResampleRCPP"]]) + 
        1]] <- list(xNumeric = xNumeric, yNumeric = yNumeric, 
        numResamples = numResamples, sampleSize = sampleSize)
    .Call("_TauStar_TStarFastResampleRCPP", PACKAGE = "TauStar", 
        xNumeric, yNumeric, numResamples, sampleSize)
}
