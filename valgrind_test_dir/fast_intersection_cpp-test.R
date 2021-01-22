function (rows, cols, values, target, unknown_dist = 1, far_dist = 5) 
{
    e <- get("data.env", .GlobalEnv)
    e[["fast_intersection_cpp"]][[length(e[["fast_intersection_cpp"]]) + 
        1]] <- list(rows = rows, cols = cols, values = values, 
        target = target, unknown_dist = unknown_dist, far_dist = far_dist)
    .Call("_uwot_fast_intersection_cpp", rows, cols, values, 
        target, unknown_dist, far_dist)
}
