function (x, alpha, eta, BL) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_detectAFFMeanMultiple"]][[length(e[["cpp_detectAFFMeanMultiple"]]) + 
        1]] <- list(x = x, alpha = alpha, eta = eta, BL = BL)
    .Call("_ffstream_cpp_detectAFFMeanMultiple", x, alpha, eta, 
        BL)
}
