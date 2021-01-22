function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["cpp_s2_geog_point"]][[length(e[["cpp_s2_geog_point"]]) + 
        1]] <- list(x = x, y = y)
    .Call("_s2_cpp_s2_geog_point", x, y)
}
