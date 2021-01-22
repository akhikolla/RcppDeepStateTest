function (x, y) 
{
    e <- get("data.env", .GlobalEnv)
    e[["whichLowerEQThanX"]][[length(e[["whichLowerEQThanX"]]) + 
        1]] <- list(x = x, y = y)
    .Call("_HistDAWass_whichLowerEQThanX", PACKAGE = "HistDAWass", 
        x, y)
}
