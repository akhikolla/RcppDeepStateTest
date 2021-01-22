function (x, lambda, alpha, BL) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_detectFFFMeanMultiple"]][[length(e[["cpp_detectFFFMeanMultiple"]]) + 
        1]] <- list(x = x, lambda = lambda, alpha = alpha, BL = BL)
    .Call("_ffstream_cpp_detectFFFMeanMultiple", x, lambda, alpha, 
        BL)
}
