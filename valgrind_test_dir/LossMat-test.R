function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["LossMat"]][[length(e[["LossMat"]]) + 1]] <- list(x = x, 
        y = y)
    .Call("_lsbclust_LossMat", x, y)
}
