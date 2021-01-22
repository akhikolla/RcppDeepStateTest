function (x, v) 
{
    e <- get("data.env", .GlobalEnv)
    e[["mySize"]][[length(e[["mySize"]]) + 1]] <- list(x = x, 
        v = v)
    .Call("_RaceID_mySize", x, v)
}
