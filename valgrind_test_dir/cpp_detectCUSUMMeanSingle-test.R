function (x, k, h, BL) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_detectCUSUMMeanSingle"]][[length(e[["cpp_detectCUSUMMeanSingle"]]) + 
        1]] <- list(x = x, k = k, h = h, BL = BL)
    .Call("_ffstream_cpp_detectCUSUMMeanSingle", x, k, h, BL)
}
