function (t, min, max, mode) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CTriC"]][[length(e[["CTriC"]]) + 1]] <- list(t = t, min = min, 
        max = max, mode = mode)
    .Call("_triangulr_CTriC", PACKAGE = "triangulr", t, min, 
        max, mode)
}
