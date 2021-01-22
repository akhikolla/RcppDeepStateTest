function (x, alpha, eta, BL) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_detectAFFMeanSingle"]][[length(e[["cpp_detectAFFMeanSingle"]]) + 
        1]] <- list(x = x, alpha = alpha, eta = eta, BL = BL)
    .Call("_ffstream_cpp_detectAFFMeanSingle", x, alpha, eta, 
        BL)
}
