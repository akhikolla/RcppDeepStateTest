function (xy, dir = 0) 
{
    e <- get("data.env", .GlobalEnv)
    e[["get_angle_cpp"]][[length(e[["get_angle_cpp"]]) + 1]] <- list(xy = xy, 
        dir = dir)
    .Call("_amt_get_angle_cpp", PACKAGE = "amt", xy, dir)
}
