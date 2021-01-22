function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["isInternalHyperlink"]][[length(e[["isInternalHyperlink"]]) + 
        1]] <- list(x = x)
    .Call("_openxlsx_isInternalHyperlink", x)
}
