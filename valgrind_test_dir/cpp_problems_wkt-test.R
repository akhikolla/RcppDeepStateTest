function (wkt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_problems_wkt"]][[length(e[["cpp_problems_wkt"]]) + 
        1]] <- list(wkt = wkt)
    .Call("_wk_cpp_problems_wkt", wkt)
}
