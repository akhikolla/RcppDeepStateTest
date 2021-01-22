function (xy, dir = 0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_angle_cpp2"]][[length(e[["get_angle_cpp2"]]) + 1]] <- list(xy = xy, 
        dir = dir)
    .Call("_amt_get_angle_cpp2", PACKAGE = "amt", xy, dir)
}
