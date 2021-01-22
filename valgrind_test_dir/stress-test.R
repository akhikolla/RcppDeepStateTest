function (x, W, D) 
{
    e <- get("data.env", .GlobalEnv)
    e[["stress"]][[length(e[["stress"]]) + 1]] <- list(x = x, 
        W = W, D = D)
    .Call("_graphlayouts_stress", x, W, D)
}
