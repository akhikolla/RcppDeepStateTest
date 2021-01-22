function (ipixelsR, width, height, sigma, flag_dct16x16) 
{
    e <- get("data.env", .GlobalEnv)
    e[["DCTdenoising"]][[length(e[["DCTdenoising"]]) + 1]] <- list(ipixelsR = ipixelsR, 
        width = width, height = height, sigma = sigma, flag_dct16x16 = flag_dct16x16)
    .Call("_imagerExtra_DCTdenoising", ipixelsR, width, height, 
        sigma, flag_dct16x16)
}
