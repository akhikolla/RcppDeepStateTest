function (fmt) 
{
    e <- get("data.env", .GlobalEnv)
    e[["removeFormats"]][[length(e[["removeFormats"]]) + 1]] <- list(fmt = fmt)
    invisible(c(".Call", "'_anytime_removeFormats`", "fmt"))
}
