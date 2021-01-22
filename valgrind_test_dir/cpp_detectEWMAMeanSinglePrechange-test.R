function (x, r, L, prechangeMean, prechangeSigma) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_detectEWMAMeanSinglePrechange"]][[length(e[["cpp_detectEWMAMeanSinglePrechange"]]) + 
        1]] <- list(x = x, r = r, L = L, prechangeMean = prechangeMean, 
        prechangeSigma = prechangeSigma)
    .Call("_ffstream_cpp_detectEWMAMeanSinglePrechange", x, r, 
        L, prechangeMean, prechangeSigma)
}
