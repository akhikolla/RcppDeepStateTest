function (val) 
{
    e <- get("data.env", .GlobalEnv)
    e[["setMaxIntAsYYYYMMDD"]][[length(e[["setMaxIntAsYYYYMMDD"]]) + 
        1]] <- list(val = val)
    invisible(c(".Call", "'_anytime_setMaxIntAsYYYYMMDD`", "val"
    ))
}
