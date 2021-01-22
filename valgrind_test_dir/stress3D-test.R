function (x, W, D) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stress3D"]][[length(e[["stress3D"]]) + 1]] <- list(x = x, 
        W = W, D = D)
    .Call("_graphlayouts_stress3D", x, W, D)
}
