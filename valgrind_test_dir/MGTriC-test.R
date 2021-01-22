function (t, min, max, mode) 
{
    e <- get("data.env", .GlobalEnv)
    e[["MGTriC"]][[length(e[["MGTriC"]]) + 1]] <- list(t = t, 
        min = min, max = max, mode = mode)
    .Call("_triangulr_MGTriC", PACKAGE = "triangulr", t, min, 
        max, mode)
}
