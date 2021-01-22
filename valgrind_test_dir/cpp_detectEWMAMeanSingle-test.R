function (x, r, L, BL) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_detectEWMAMeanSingle"]][[length(e[["cpp_detectEWMAMeanSingle"]]) + 
        1]] <- list(x = x, r = r, L = L, BL = BL)
    .Call("_ffstream_cpp_detectEWMAMeanSingle", x, r, L, BL)
}
