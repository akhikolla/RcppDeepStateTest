function (p, i_dist, j_dist, x_center, y_center, x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["dist_dist_diff"]][[length(e[["dist_dist_diff"]]) + 1]] <- list(p = p, 
        i_dist = i_dist, j_dist = j_dist, x_center = x_center, 
        y_center = y_center, x = x, y = y)
    .Call("_redist_dist_dist_diff", p, i_dist, j_dist, x_center, 
        y_center, x, y)
}
