function (x, v) 
{
    e <- get("data.env", .GlobalEnv)
    e[["myVar"]][[length(e[["myVar"]]) + 1]] <- list(x = x, v = v)
    .Call("_RaceID_myVar", x, v)
}
