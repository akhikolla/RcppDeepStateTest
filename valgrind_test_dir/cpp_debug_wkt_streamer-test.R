function (input) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_debug_wkt_streamer"]][[length(e[["cpp_debug_wkt_streamer"]]) + 
        1]] <- list(input = input)
    invisible(c(".Call", "'_wkutils_cpp_debug_wkt_streamer`", 
    "input"))
}
