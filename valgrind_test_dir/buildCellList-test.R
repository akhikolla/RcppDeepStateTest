function (r, t, v) 
{
    e <- get("data.env", .GlobalEnv)
    e[["buildCellList"]][[length(e[["buildCellList"]]) + 1]] <- list(r = r, 
        t = t, v = v)
    .Call("_openxlsx_buildCellList", r, t, v)
}
