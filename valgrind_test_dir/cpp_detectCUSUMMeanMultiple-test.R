function (x, k, h, BL) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_detectCUSUMMeanMultiple"]][[length(e[["cpp_detectCUSUMMeanMultiple"]]) + 
        1]] <- list(x = x, k = k, h = h, BL = BL)
    .Call("_ffstream_cpp_detectCUSUMMeanMultiple", x, k, h, BL)
}
