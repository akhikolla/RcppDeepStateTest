function (x, W, D) 
{
    e <- get("data.env", .GlobalEnv)
    e[["constrained_stress3D"]][[length(e[["constrained_stress3D"]]) + 
        1]] <- list(x = x, W = W, D = D)
    .Call("_graphlayouts_constrained_stress3D", x, W, D)
}
