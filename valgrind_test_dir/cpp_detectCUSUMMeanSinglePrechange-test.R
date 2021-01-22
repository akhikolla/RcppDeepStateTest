function (x, k, h, prechangeMean, prechangeSigma) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_detectCUSUMMeanSinglePrechange"]][[length(e[["cpp_detectCUSUMMeanSinglePrechange"]]) + 
        1]] <- list(x = x, k = k, h = h, prechangeMean = prechangeMean, 
        prechangeSigma = prechangeSigma)
    .Call("_ffstream_cpp_detectCUSUMMeanSinglePrechange", x, 
        k, h, prechangeMean, prechangeSigma)
}
