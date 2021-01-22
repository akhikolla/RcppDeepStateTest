function (x, y, featureId) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_s2_make_line"]][[length(e[["cpp_s2_make_line"]]) + 
        1]] <- list(x = x, y = y, featureId = featureId)
    .Call("_s2_cpp_s2_make_line", x, y, featureId)
}
