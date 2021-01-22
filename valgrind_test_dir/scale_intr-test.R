function (X, pair_x, pair_y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["scale_intr"]][[length(e[["scale_intr"]]) + 1]] <- list(X = X, 
        pair_x = pair_x, pair_y = pair_y)
    .Call("_xyz_scale_intr", X, pair_x, pair_y)
}
