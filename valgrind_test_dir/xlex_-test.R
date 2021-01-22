function (x) 
{
    e <- get("data.env", .GlobalEnv)
    e[["xlex_"]][[length(e[["xlex_"]]) + 1]] <- list(x = x)
    .Call("_tidyxl_xlex_", PACKAGE = "tidyxl", x)
}
