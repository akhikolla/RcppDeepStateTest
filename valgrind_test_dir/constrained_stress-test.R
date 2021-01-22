function (x, W, D) 
{
    e <- get("data.env", .GlobalEnv)
    e[["constrained_stress"]][[length(e[["constrained_stress"]]) + 
        1]] <- list(x = x, W = W, D = D)
    .Call("_graphlayouts_constrained_stress", x, W, D)
}
