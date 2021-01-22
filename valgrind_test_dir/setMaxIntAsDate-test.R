function (val) 
{
    e <- get("data.env", .GlobalEnv)
    e[["setMaxIntAsDate"]][[length(e[["setMaxIntAsDate"]]) + 
        1]] <- list(val = val)
    invisible(c(".Call", "'_anytime_setMaxIntAsDate`", "val"))
}
