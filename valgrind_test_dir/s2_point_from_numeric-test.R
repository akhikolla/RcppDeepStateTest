function (x, y, z) 
{
    e <- get("data.env", .GlobalEnv)
    e[["s2_point_from_numeric"]][[length(e[["s2_point_from_numeric"]]) + 
        1]] <- list(x = x, y = y, z = z)
    .Call("_s2_s2_point_from_numeric", x, y, z)
}
