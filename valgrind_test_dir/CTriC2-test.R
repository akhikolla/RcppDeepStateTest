function (t, min, max, mode) 
{
    e <- get("data.env", .GlobalEnv)
    e[["CTriC2"]][[length(e[["CTriC2"]]) + 1]] <- list(t = t, 
        min = min, max = max, mode = mode)
    .Call("_triangulr_CTriC2", PACKAGE = "triangulr", t, min, 
        max, mode)
}
