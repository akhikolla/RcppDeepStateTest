function (x, lambda, alpha, prechangeMean, prechangeSigma) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_detectFFFMeanSinglePrechange"]][[length(e[["cpp_detectFFFMeanSinglePrechange"]]) + 
        1]] <- list(x = x, lambda = lambda, alpha = alpha, prechangeMean = prechangeMean, 
        prechangeSigma = prechangeSigma)
    .Call("_ffstream_cpp_detectFFFMeanSinglePrechange", x, lambda, 
        alpha, prechangeMean, prechangeSigma)
}
