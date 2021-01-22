function () 
{
    e <- get("data.env", .GlobalEnv)
    e[["saturationVapourPressure"]][[length(e[["saturationVapourPressure"]]) + 
        1]] <- list()
    list(NULL, character(0))
}
