function (x, r, L, BL) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_detectEWMAMeanMultiple"]][[length(e[["cpp_detectEWMAMeanMultiple"]]) + 
        1]] <- list(x = x, r = r, L = L, BL = BL)
    .Call("_ffstream_cpp_detectEWMAMeanMultiple", x, r, L, BL)
}
