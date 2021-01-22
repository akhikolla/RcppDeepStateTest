function (x, alpha, eta, prechangeMean, prechangeSigma) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_detectAFFMeanSinglePrechange"]][[length(e[["cpp_detectAFFMeanSinglePrechange"]]) + 
        1]] <- list(x = x, alpha = alpha, eta = eta, prechangeMean = prechangeMean, 
        prechangeSigma = prechangeSigma)
    .Call("_ffstream_cpp_detectAFFMeanSinglePrechange", x, alpha, 
        eta, prechangeMean, prechangeSigma)
}
