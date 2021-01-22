function (x, v, w) 
{
    e <- get("data.env", .GlobalEnv)
    e[["applyProb"]][[length(e[["applyProb"]]) + 1]] <- list(x = x, 
        v = v, w = w)
    .Call("_RaceID_applyProb", x, v, w)
}
