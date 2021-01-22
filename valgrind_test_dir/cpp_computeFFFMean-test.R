function (x, lambda) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_computeFFFMean"]][[length(e[["cpp_computeFFFMean"]]) + 
        1]] <- list(x = x, lambda = lambda)
    .Call("_ffstream_cpp_computeFFFMean", x, lambda)
}
