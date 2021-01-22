function (x, eta) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_computeAFFMean"]][[length(e[["cpp_computeAFFMean"]]) + 
        1]] <- list(x = x, eta = eta)
    .Call("_ffstream_cpp_computeAFFMean", x, eta)
}
