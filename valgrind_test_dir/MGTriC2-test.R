function (t, min, max, mode) 
{
    e <- get("data.env", .GlobalEnv)
    e[["MGTriC2"]][[length(e[["MGTriC2"]]) + 1]] <- list(t = t, 
        min = min, max = max, mode = mode)
    .Call("_triangulr_MGTriC2", PACKAGE = "triangulr", t, min, 
        max, mode)
}
