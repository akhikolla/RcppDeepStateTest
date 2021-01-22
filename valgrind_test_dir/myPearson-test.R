function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["myPearson"]][[length(e[["myPearson"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_segmenTier_myPearson", PACKAGE = "segmenTier", x, 
        y)
}
