function (input) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_debug_wkt"]][[length(e[["cpp_debug_wkt"]]) + 1]] <- list(input = input)
    invisible(c(".Call", "'_wkutils_cpp_debug_wkt`", "input"))
}
