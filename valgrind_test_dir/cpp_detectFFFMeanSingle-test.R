function (x, lambda, alpha, BL) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_detectFFFMeanSingle"]][[length(e[["cpp_detectFFFMeanSingle"]]) + 
        1]] <- list(x = x, lambda = lambda, alpha = alpha, BL = BL)
    .Call("_ffstream_cpp_detectFFFMeanSingle", x, lambda, alpha, 
        BL)
}
